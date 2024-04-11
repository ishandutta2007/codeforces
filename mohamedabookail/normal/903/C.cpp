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
  int n; cin >> n;
  map < int, int > mp;
  int nemo = 0;
  for(int i = 0; i < n; i++) {
    int oo; cin >> oo;
	mp[oo] ++;
	nemo = max(nemo, mp[oo]);
  }
  cout << nemo << endl;
}