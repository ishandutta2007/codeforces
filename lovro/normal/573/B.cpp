#define NDEBUG
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> inline bool makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
    return true;
  }
  return false;
}
template<typename T, typename U> inline bool makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0); // caret here

  int n;
  cin >> n;
  vector<int> h(n);
  for (int& x : h) {
    cin >> x;
  }

  vector<int> distl(n), distr(n);
  {
    int d = 0;
    for (int i=0; i<n; ++i) {
      ++d;
      makemin(d, h[i]);
      distl[i] = d;
    }
  }
  {
    int d = 0;
    for (int i=n-1; i>=0; --i) {
      ++d;
      makemin(d, h[i]);
      distr[i] = d;
    }
  }

  int ans = 0;
  for (int i=0; i<n; ++i) {
    int e = min(distl[i], distr[i]);
    makemax(ans, e);
  }
  cout << ans << '\n';
}