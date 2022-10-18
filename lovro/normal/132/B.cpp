#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename T> inline int get_bit ( const T &x, int index ) { return (int)((x >> index) & 1); }

const int MAXM = 55;
int R, S;
char board[MAXM][MAXM+1];

enum { RIGHT=0, DOWN=1, LEFT=2, UP=3 };
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

bool inside(int y, int x) {
  return y >= 0 && y < R && x >= 0 && x < S;
}

struct State {
  int y, x, dp, cp;

  void advance_to_edge() {
    int dir = dp;
    for (int i=0; i<2; ++i) {
      while (1) {
        int ny = y+dy[dir], nx = x+dx[dir];
        if (!inside(ny, nx) || board[ny][nx] != board[y][x]) {
          break;
        }
        y = ny; x = nx;
      }
      dir = (dir+cp+4)%4;
    }
  }

  State next() const {
    int ny = y+dy[dp], nx = x+dx[dp];
    if (inside(ny, nx) && board[ny][nx] > 0) {
      State result = {ny, nx, dp, cp};
      return result;
    }

    if (cp == -1) {
      State result = {y, x, dp, 1};
      return result;
    }

    State result = {y, x, (dp+1) % 4, -1};
    return result;
  }

  friend bool operator<(const State &s1, const State &s2) {
    if (s1.y != s2.y) return s1.y < s2.y;
    if (s1.x != s2.x) return s1.x < s2.x;
    if (s1.dp != s2.dp) return s1.dp < s2.dp;
    if (s1.cp != s2.cp) return s1.cp < s2.cp;
    return false;
  }
};

const int MAXLOG = 30;
map<State, State> memo[MAXLOG+1];
State calc(const State &S, int log_moves) {
  map<State, State>::iterator it = memo[log_moves].find(S);
  if (it != memo[log_moves].end()) {
    return it->second;
  }

  State result;
  if (log_moves == 0) {
    result = S.next();
    result.advance_to_edge();
  } else {
    result = calc(S, log_moves-1);
    result = calc(result, log_moves-1);
  }
  memo[log_moves].insert(make_pair(S, result));
  return result;
}

int main() {
  cin.sync_with_stdio(0);

  int moves;
  cin >> R >> moves;

  for (int i=0; i<R; ++i) {
    string row;
    cin >> row;
    S = row.size();
    for (int j=0; j<S; ++j) {
      board[i][j] = row[j] - '0';
    }
  }

  State S = { 0, 0, RIGHT, -1 };
  S.advance_to_edge();
  for (int i=0; i<MAXLOG; ++i) {
    if (get_bit(moves, i)) {
      S = calc(S, i);
    }
  }
  cout << int(board[S.y][S.x]) << "\n";

  return 0;
}