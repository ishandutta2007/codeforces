/**
 *    author:  Mohamed Abo_Okail
 *    created: 1O/O6/2O2O
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
		vector < int > v(n), flag;
		int ind = 0, ind1 = 0;
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] == 1) ind = i;
			if(v[i] == 2) ind1 = i;
		}
		if((ind == ind1 - 1 || ind == n - 1) && ind != ind1 + 1) {
			for (int i = ind; i < n; i++) {
				flag.push_back(v[i]);
			}
			for (int i = 0; i < ind; i++) {
				flag.push_back(v[i]);
			}
		}
		else {
			for (int i = ind; i >= 0 ; i--) {
				flag.push_back(v[i]);
			}
			for (int i = n - 1; i > ind ; i--) {
				flag.push_back(v[i]);
			}
		}
		for (int i = 1; i < n; i++) {
			if(flag[i] < flag[i - 1]) bol = 0;
		}
		cout << (ind == ind1 || bol ? "YES" : "NO") << endl;
	}
}