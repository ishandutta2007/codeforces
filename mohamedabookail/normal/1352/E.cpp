/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O5/2O2O
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
		int n; cin >> n;
		vector < int > v(n), a(n + 1, 0), b(n + 1, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			a[v[i]] = 1;
		}
		for (int i = 0; i < n; i++) {
			int cur = v[i];
			for (int j = i + 1; j < n; j++) {
				cur += v[j];
				if(cur > n) break;
				if(a[cur] == 1) b[cur] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			if(b[v[i]]) cnt++;
		}
		cout << cnt <<  endl;
	}
}