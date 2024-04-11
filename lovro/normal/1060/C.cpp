#define NDEBUG
#include <climits>
#include <cstdint>
#include <iostream>
#include <utility>

// <lib>
typedef uint64_t u64;
typedef uint32_t u32;
template <typename T, typename U> inline bool makemin(T& res, const U& x) {
  if (x < res) {
    res = x;
    return true;
  }
  return false;
}
template <typename T, typename U> inline bool makemax(T& res, const U& x) {
  if (x > res) {
    res = x;
    return true;
  }
  return false;
}
// </lib>
using namespace std;

const int MAXN = 2005;
u64 csum[MAXN][MAXN];

u64 matsum(int y1, int y2, int x1, int x2) {
  return csum[y2][x2] - csum[y2][x1-1] - csum[y1-1][x2] + csum[y1-1][x1-1];
}

int main() {
  ios_base::sync_with_stdio(false);
  int R, C;
  cin >> C >> R;
  static u32 A[MAXN], B[MAXN];
  for (int j=1; j<=C; ++j) cin >> A[j];
  for (int i=1; i<=R; ++i) cin >> B[i];
  for (int i=1; i<=R; ++i) {
    for (int j=1; j<=C; ++j) {
      csum[i][j] = csum[i][j-1] + csum[i-1][j] + B[i] * A[j] - csum[i-1][j-1];
    }
  }
  u64 maxsum;
  cin >> maxsum;

  int ans = 0;
  for (int nrows = 1; nrows <= R; ++nrows) {
    u64 bsum = 0;
    for (int y = 1; y < nrows; ++y) {
      bsum += B[y];
    }
    pair<u64, int> best(INT_MAX, 0);
    for (int y1 = 1, y2 = y1 + nrows - 1; y2 <= R; ++y1, ++y2) {
      bsum += B[y2];
      makemin(best, make_pair(bsum, y1));
      bsum -= B[y1];
    }
    const int y1 = best.second, y2 = y1 + nrows - 1;
    int maxw = 0;
    for (int x1 = 1, x2 = 0; x1 <= C; ++x1) {
      makemax(x2, x1 - 1);
      while (x2 < C && matsum(y1, y2, x1, x2 + 1) <= maxsum) {
        ++x2;
      }
      makemax(maxw, x2 - x1 + 1);
    }
    makemax(ans, (y2 - y1 + 1) * maxw);
  }
  cout << ans << '\n';
}