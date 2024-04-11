#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  while (T-- > 0) {
    char input[100];
    cin >> input;
    int row, column;
    string column_str;
    if (sscanf(input, "R%dC%d", &row, &column) == 2) {
      --column;
      for (int p26=26, len=1;; p26*=26, ++len) {
    if (column < p26) {
      column_str.resize(len);
      for (int i=len-1; i>=0; --i) {
        column_str[i] = 'A' + column % 26;
        column /= 26;
      }
      cout << column_str << row << endl;
      break;
    } else {
      column -= p26;
    }
      }
    } else {
      for (int boost=0, p26=1, len=0, parsed=0;; p26*=26, ++len) {
    if (isdigit(input[len])) {
      cout << 'R' << input+len << 'C' << boost+parsed << endl;
      break;
    } else {
      parsed = 26*parsed + input[len] - 'A';
    }
    boost += p26;
      }
    }
  }
}