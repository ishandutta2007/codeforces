/**
*    author:  Mohamed Abo_Okail
*    created: 23/O6/2O2O
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
  int tt; cin >> tt;
  while(tt --) {
    int n; string s, t, h; cin >> n >> s;
	int indx = 0, a = 0, b = 0;
	for(int i = 0; i < n; i++) {
      if(s[i] == '1') {
        indx = i;
		break;
      }
	  t.push_back('0');
	}
    for(int i = indx; i < n; i++) {
      if(s[i] == '1') {
        if(b) h.push_back('0');
        if(b) a = 0;
        a ++;
        b = 0;
	  }
	  else b ++;
    }
	if(a && b) {
      h.push_back('0');
      a = 0;
      b = 0;
	}
	if(sz(h)) t.push_back('0');
    string q(a, '1');
    cout << t << q << endl;
  }
}