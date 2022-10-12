/**
*    author:  Mohamed Abo_Okail
*    created: 22/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define endl "\n"
#define ll long long
#define sz(x) int(x.size())

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  int n, k; cin >> n >> k;
  vector < int > a(n), b(n);
  vector < pair < int, pair < int, int > > > flag;
  int ans = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    if(a[i] <= b[i]) ans += a[i], cnt ++;
	else {
	  flag.push_back(make_pair(a[i] - b[i], make_pair(a[i], b[i])));
	}
  }
  if(sz(flag)) sort(flag.begin(), flag.end());
  for(int i = 0; i < sz(flag); i++) {
    if(cnt < k) ans += flag[i].second.first, cnt++;
    else ans += flag[i].second.second;
  }
  cout << ans << endl;
}