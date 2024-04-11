/**
 *    author:  Mohamed Abo_Okail
 *    created: 31/O5/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		vector < pair < int, int > > a(s.size() + 1), b(s.size() + 1);
		int cntO = 0, cntZ = 0, cntOO = 0, cntZZ = 0, ans = 1e3;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == '1') cntO++; else cntZ++;
			a[i].first = cntO;
			a[i].second = cntZ;
		}
		for (int i = s.size() - 1; i >= 0 ; i--) {
			if(s[i] == '1') cntOO++; else cntZZ++;
			b[i].first = cntOO;
			b[i].second = cntZZ;
		}
		for (int i = 0; i < s.size() - 1; i++) {
			ans = min(ans, a[i].second + b[i + 1].first);
			ans = min(ans, a[i].first + b[i + 1].second);
		}
		cout << (ans == 1e3 ? 0 : min({ans, cntO, cntZ})) << endl;
	}
}