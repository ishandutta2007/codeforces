
/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O6/2O2O
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
	int n; cin >> n;
	deque < int > a(n), b(n), c(n);
	map < int, int > mp, mx, my;
	vector < int > v, t;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		mp[b[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		if(mp[a[i]] == i) v.push_back(0);
		else if(mp[a[i]] == n - 1 && i == 0) v.push_back(1);
		else  v.push_back(i - mp[a[i]]);
	}
	for (int i = 0; i < n; i++) {
		if(mp[a[i]] == i) t.push_back(0);
		else if(mp[a[i]] == 0 && i == n - 1) t.push_back(-1);
		else if(mp[a[i]] > i) t.push_back(n - (mp[a[i]] + 1) + i + 1);
		else t.push_back(i - mp[a[i]]);
	}
	for (int i = 0; i < v.size(); i++) {
		mx[v[i]]++;
		my[t[i]]++;
		ans = max(ans, mx[v[i]]);
		ans = max(ans, my[t[i]]);
	}
	cout << ans << endl;
}