#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
template <typename T> inline int get_bit(const T &x, int index) {
  return int((x >> index) & 1);
}
#define MINUSONE(v) memset((v), -1, sizeof (v))
#define ALL(x) (x).begin(), (x).end()

const int MAXR = 101;

int memo[MAXR][MAXR][4][4];

vector<char> seen_stack[128];

int calc(int y1, int y2, int up, int down, int depth) {
  if (y1 > y2) {
    return 0;
  }

  if (y1 == y2) {
    up &= down;
    down &= up;
  }

  int &ret = memo[y1][y2][up][down];
  if (ret != -1) {
    return ret;
  }

  // fprintf(stderr, "calc(y1=%d, y2=%d, up=%d, down=%d)\n", y1, y2, up, down);

  vector<char> &seen = seen_stack[depth]; seen.clear();
  for (int y=y1; y<=y2; ++y) {
    for (int x=0; x<2; ++x) {
      bool allowed =
        (y == y1 && get_bit(up, x)) ||
        (y == y2 && get_bit(down, x)) ||
        (y > y1 && y < y2);
      if (!allowed) {
        continue;
      }

      int sg =
        calc(y1, y-1, up, 1<<x, depth+1) ^
        calc(y+1, y2, 1<<x, down, depth+1);

      if (sg >= (int)seen.size()) {
        seen.resize(sg+1, 0);
      }
      seen[sg] = 1;
    }
  }

  for (ret=0; ret<(int)seen.size() && seen[ret]; ++ret) ;
  // fprintf(stderr, "calc(y1=%d, y2=%d, up=%d, down=%d) = %d\n", y1, y2, up, down, ret);
  return ret;
}

int main() {
  cin.sync_with_stdio(0);

  int R, n;
  cin >> R >> n;

  vector<pair<int, int> > blocks;
  repeat (n) {
    int a, b;
    cin >> a >> b;
    blocks.push_back(make_pair(a-1, b-1));
  }
  sort(ALL(blocks));

  MINUSONE(memo);

  int total_sg = 0;
  int start = 0, up = 3;
  for (auto p : blocks) {
    int y = p.first, b = p.second;
    int down = 1 << b;
    if (y > start) {
      total_sg ^= calc(start, y-1, up, down, 0);
    }
    start = y+1;
    up = down;
  }

  if (start < R) {
    total_sg ^= calc(start, R-1, up, 3, 0);
  }

  cout << (total_sg ? "WIN" : "LOSE") << '\n';
  return 0;
}