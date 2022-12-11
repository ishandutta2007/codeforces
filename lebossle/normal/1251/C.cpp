#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

void solve() {
  string s;
  cin >> s;
  string sOdd, sEven;
  for (char c : s)
    (c%2==0 ? sEven : sOdd).push_back(c);
  string ans;
  int iOdd=0, iEven=0;
  while (iOdd < sOdd.size() || iEven < sEven.size()) {
    if (iOdd == sOdd.size())
      ans.push_back(sEven[iEven++]);
    else if (iEven == sEven.size())
      ans.push_back(sOdd[iOdd++]);
    else if (sOdd[iOdd] < sEven[iEven])
      ans.push_back(sOdd[iOdd++]);
    else
      ans.push_back(sEven[iEven++]);
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