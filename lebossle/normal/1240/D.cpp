#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  vector<int> corresp(n, n);
  vector<map<int, int>> candCorresp(n+1);
  for (int i=n-1; i>=0; --i) {
    if (candCorresp[i+1].count(a[i])) {
      corresp[i] = candCorresp[i+1][a[i]];
      swap(candCorresp[i], candCorresp[corresp[i]+1]);
    }
    candCorresp[i][a[i]] = i;
  }
  vector<lli> amt(n+1, 0);
  for (int i=n-1; i>=0; --i)
    if (corresp[i] != n)
      amt[i] = amt[corresp[i]+1]+1;
  lli ans=0;
  for (lli x : amt)
    ans += x;
  cout << ans << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i=0; i<q; ++i)
    solve();
}