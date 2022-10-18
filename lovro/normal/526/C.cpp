#define NDEBUG
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}
typedef long long int64;

const int WTHRESH = 100;

int main() {
  ios_base::sync_with_stdio(0);

  int64 C, w[2], val[2];
  cin >> C >> val[0] >> val[1] >> w[0] >> w[1];

  int64 ans = 0;
  if (max(w[0], w[1]) > WTHRESH) {
    if (w[1] > w[0]) {
      swap(w[0], w[1]);
      swap(val[0], val[1]);
    }
    assert(w[0] >= w[1]);
    for (int64 c0=0; c0*w[0] <= C; ++c0) {
      makemax(ans, c0*val[0] + (C - c0*w[0])/w[1]*val[1]);
    }
  } else {
    if (val[0]*w[1] > val[1]*w[0]) {
      swap(w[0], w[1]);
      swap(val[0], val[1]);
    }
    assert(double(val[0])/w[0] <= double(val[1])/w[1]);
    for (int64 c0=0; c0 <= 1000000 && c0*w[0] <= C; ++c0) {
      makemax(ans, c0*val[0] + (C - c0*w[0])/w[1]*val[1]);
    }
  }
  cout << ans << '\n';
}