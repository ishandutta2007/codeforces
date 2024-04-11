#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
  vector<long long> v;
  for(int i = 1; i <= 9; i++) {
    for(int j = 0; j < 1 << i; j++) {
      int x = 0;
      for(int k = 0; k < i; k++) {
        x *= 10;
        x += (j & 1 << k) ? 7 : 4;
      }
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());
  v.push_back(4444444444ll);

  long long result = 0;
  int lo, hi; cin >> lo >> hi; hi++;
  while(lo < hi) {
    long long nxt = *lower_bound(v.begin(), v.end(), lo);
    long long nxv = min(nxt + 1, 1ll * hi);
    result += (nxv - lo) * nxt;
    lo = nxv;
  }
  cout << result << endl;
}