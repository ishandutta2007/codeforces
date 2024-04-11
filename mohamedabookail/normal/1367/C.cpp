/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O6/2O2O
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
	int t; cin >> t;
	while(t --) {
		int n, k; string s; cin >> n >> k >> s;
		vector < int > v;
		s.push_back('1');
		int cnt = 0, ans = 0;
		for (int i = 0; i <= n; i++) {
			if(s[i] == '0') cnt ++;
			else {
				if(cnt) v.push_back(cnt);
				cnt = 0;
			}
		}
		s.pop_back();
		for (int i = 0; i < v.size(); i++) {
			if(s.back() == '0' && i == v.size() - 1) v[i] += k;
			v[i] -= k;
			int cnt = 0;
			for (int j = 0; j < v[i]; j++) {
				if(s.front() == '0' && !i && !j) {
					ans ++;
					continue;
				}
				cnt ++;
				if(cnt == k + 1) ans ++, cnt = 0;
			}
		}
		cout << ans << endl;
	}
}