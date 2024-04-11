#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

void solve() {
  lli n;
  cin >> n;
  set<lli> ans;
  lli i;
  for (i=0; i*i<=n; ++i)
    ans.insert(i);
  for (; i>0; --i)
    ans.insert(n/i);
  cout << ans.size() << '\n';
  for (lli i : ans)
    cout << i << ' ';
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}