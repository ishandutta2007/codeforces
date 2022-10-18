#include <iostream>
#include <string>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  repeat (T) {
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    string board[8];
    for (int i=0; i<8; ++i) {
      cin >> board[i];
      for (int j=0; j<8; ++j) {
        if (board[i][j] == 'K') {
          if (x1 == -1) {
            y1 = i;
            x1 = j;
          } else {
            y2 = i;
            x2 = j;
          }
        }
      }
    }
    bool ans = y1 % 4 == y2 % 4 && x1 % 4 == x2 % 4;
    cout << (ans ? "YES" : "NO") << '\n';
  }

  return 0;
}