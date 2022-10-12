/**
 *    author:  Mohamed Abo_Okail
 *    created: O6/O6/2O2O
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
	int n, k; cin >> n >> k;
	vector < pair < int, int > > v(n);
	map < int, int > mp;
	map < pair < int, int >, int > flag;
	int cnt = 1, a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		mp[v[i].first]++;
		flag[{v[i].first, v[i].second}]++;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + mp[v[i].first] - 1; j >= i ; j--) {
			if(cnt == k) {
				a = v[j].first;
				b = v[j].second;
			}
			cnt++;
		}
		i = i + mp[v[i].first] - 1;
	}
	cout << flag[{a, b}] << endl;
}