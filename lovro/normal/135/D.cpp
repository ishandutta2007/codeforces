#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


const int MAXN = 1005;

int R, C;
char board[MAXN][MAXN+1];
bool vis0[MAXN][MAXN];
int time1[MAXN][MAXN], vis1[MAXN][MAXN];
int TIME = 1;

int best = 0;
void examine(int y, int x) {
  queue<pair<int, int> > q;
  vis0[y][x] = 1;
  q.push(make_pair(y, x));

  static const int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
  static const int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

  vector<pair<int, int> > border;
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second; q.pop();

    for (int dir=0; dir<8; ++dir) {
      int ny = y+dy[dir], nx = x+dx[dir];
      if (ny < 0 || ny >= R) return;
      if (nx < 0 || nx >= C) return;
      if (board[ny][nx] == '0' && !vis0[ny][nx]) {
        vis0[ny][nx] = 1;
        q.push(make_pair(ny, nx));
      } else if (board[ny][nx] == '1') {
        if (time1[ny][nx] < TIME) {
          border.push_back(make_pair(ny, nx));
          time1[ny][nx] = TIME;
        }
      }
    }
  }

  if ((int)border.size() <= best) {
    return;
  }

  assert(q.empty());
  assert(!border.empty());
  y = border[0].first, x = border[0].second;
  vis1[y][x] = TIME;
  q.push(border[0]);

  int found = 0;
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second; q.pop();
    ++found;

    int deg = 0;
    for (int dir=0; dir<8; ++dir) {
      int ny = y+dy[dir], nx = x+dx[dir];
      if (ny < 0 || ny >= R) continue;
      if (nx < 0 || nx >= C) continue;
      bool edge = dy[dir] == 0 || dx[dir] == 0;
      if (edge && time1[ny][nx] == TIME) {
        ++deg;
        if (vis1[ny][nx] != TIME) {
          vis1[ny][nx] = TIME;
          q.push(make_pair(ny, nx));
        }
      }
    }

    if (deg != 2) {
      return;
    }
  }

  if (found == (int)border.size()) {
    best = border.size();
  }
}

int main() {
  cin.sync_with_stdio(0);

  cin >> R >> C;
  for (int y=0; y<R; ++y) {
    cin >> board[y];
  }

  for (int y=0; y<R; ++y) {
    for (int x=0; x<C; ++x) {
      if (board[y][x] == '1' && board[y][x+1] == '1' &&
          board[y+1][x] == '1' && board[y+1][x+1] == '1') {
        best = 4;
      }
    }
  }

  for (int y=0; y<R; ++y) {
    for (int x=0; x<C; ++x) {
      if (board[y][x] == '0' && !vis0[y][x]) {
        ++TIME;
        examine(y, x);
      }
    }
  }

  cout << best << '\n';

  return 0;
}