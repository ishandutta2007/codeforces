#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MINUSONE(v) memset(v, -1, sizeof v)

char board[8][10];
const int MAXSTEPS = 100;
int memo[MAXSTEPS+1][8][8];

bool isinside(int x, int y) {
  return x >= 0 && x<8 && y >= 0 && y<8;
}

bool isstatue(int x, int y) {
  return isinside(x, y) && board[y][x] == 'S';
}

bool calc(int t, int y, int x) {
  if (t > MAXSTEPS) {
    return 0;
  }

  if (!isinside(x, y)) return 0;
  if (isstatue(x, y-t)) return 0;
  if (y == 0 && x == 7) return 1;

  
  int &ret = memo[t][y][x];
  if (ret != -1) {
    return ret;
  }

  ret = 0;
  static const int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1, 0 };
  static const int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0, 0 };
  for (int dir=0; dir<9; ++dir) {
    int nx = x+dx[dir], ny = y+dy[dir];
    if (isinside(ny, nx) && !isstatue(nx, ny-t)) {
      ret |= calc(t+1, ny, nx);
    }
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(0);
  for (int i=0; i<8; ++i) {
    cin >> board[i];
  }

  MINUSONE(memo);
  cout << (calc(0, 7, 0) ? "WIN" : "LOSE") << endl;

  return 0;
}