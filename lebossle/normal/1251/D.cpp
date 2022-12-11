#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

bool canBeMedian(lli s, lli m, vector<pair<lli, lli>> v) {
  vector<pair<lli, lli>> idk;
  int nth = v.size()/2;
  for (auto p : v) {
    if (p.first > m) {
      s -= p.first;
    } else if (p.second < m) {
      s -= p.first;
      nth--;
    } else {
      idk.push_back(p);
    }
  }
  if (nth < 0)
    return false;
  if (idk.size() <= nth)
    return true;
  sort(idk.begin(), idk.end());
  for (int i=0; i<nth; ++i)
    s -= idk[i].first;
  for (int i=nth; i<idk.size(); ++i)
    s -= m;
  return s >= 0;
}

void solve() {
  int n;
  lli s;
  cin >> n >> s;
  vector<pair<lli, lli>> v(n);
  for (auto& p : v)
    cin >> p.first >> p.second;
  sort(v.begin(), v.end());
  lli l=v[n/2].first, r=s+1;
  while (r-l>1) {
    lli m = (l+r)/2;
    if (canBeMedian(s, m, v))
      l = m;
    else
      r = m;
  }
  cout << l << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int ta=0; ta<q; ++ta)
    solve();
}