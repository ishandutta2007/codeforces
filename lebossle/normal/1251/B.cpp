#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (string& s : v)
    cin >> s;
  vector<int> amt(2, 0);
  vector<int> sz(n);
  for (int i=0; i<n; ++i) {
    sz[i] = v[i].size();
    for (char c : v[i])
      amt[c-'0']++;
  }
  sort(sz.begin(), sz.end());
  int amtPairs = amt[0]/2 + amt[1]/2;
  int amtAlone = amt[0]%2 + amt[1]%2;
  int ans=0;
  for (int i : sz) {
    if (i%2==1) {
      if (amtAlone == 0) {
        if (amtPairs == 0)
          break;
        amtPairs--;
        amtAlone += 2;
      }
      amtAlone--;
    }
    if (i/2 > amtPairs)
      break;
    amtPairs -= i/2;
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int ta=0; ta<q; ++ta)
    solve();
}