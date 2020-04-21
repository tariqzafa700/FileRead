#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  int nTests;
  string line;
  ifstream fin( "filereader.txt" );
  vector<vector<int>> matrix;
  stringstream ss;

  if (fin)  {
    getline(fin, line);
    ss << line;
    ss >> nTests;
    ss.clear();
    int row, col;
    for (int i = 0; i < nTests; ++i) {
      getline(fin, line);
      ss << line;
      ss >> row >> col;
      matrix.resize(row);
      for (int j = 0; j < row; ++j) {
        matrix[j].resize(col);
        getline(fin, line);
        ss << line;
        cout << line << endl;
        
        for (int k = 0; k < col; ++k) {
          ss >> matrix[j][k];
        }
        ss.clear();
      }
    }
    
    fin.close();

    for (int j = 0; j < row; ++j) {
      for (int k = 0; k < col; ++k) {
        cout << matrix[j][k] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
