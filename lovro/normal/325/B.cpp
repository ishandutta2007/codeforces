#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;
#define ALL(x) (x).begin(), (x).end()

int64 oddf(int64 x, int neven) {
  int64 ans = 0;
  for (int i=0; i<neven; ++i) {
    ans += x << i;
  }
  ans += x * (x-1) / 2;
  return ans;
}

int64 calc_odd(int64 games, int neven) {
  int64 lo = 1, hi;
  for (hi=1; oddf(hi, neven) < games; hi*=2) ;
  while (lo < hi) {
    int64 mid = (lo + hi + 1) / 2;
    if (oddf(mid, neven) <= games) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo % 2 == 1 && oddf(lo, neven) == games ? lo << neven : -1;
}

int main() {
  cin.sync_with_stdio(0);

  int64 n;
  cin >> n;

  vector<int64> ans;
  for (int neven = 0; oddf(1, neven) <= n; ++neven) {
    int64 nodd = calc_odd(n, neven);
    if (nodd != -1) {
      ans.push_back(nodd);
    }
  }

  sort(ALL(ans));
  if (ans.empty()) {
    cout << "-1\n";
  } else {
    for (int i=0; i<(int)ans.size(); ++i) {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}