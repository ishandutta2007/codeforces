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
	int n; cin >> n;
	int flag = n * 2, cur = 0;
	bool bol = 1, bol1 = 1;
	for (int i = 0; i < n * 2 + 1; i++) {
		for (int j = 0; j < flag; j++) {
			cout << ' ';
		}
		if(!flag) bol = 0;
		if(bol) flag -= 2;
		if(!bol) flag += 2;
		cout << 0;
		if(i && i != n * 2) cout << ' ';
		int cnt = 1; bool bol2 = 1;
		for (int j = 0; j < 2 * cur - 1; j++) {
			cout << cnt << ' ';
			if(cnt == cur) bol2 = 0;
			if(bol2) cnt++;
			if(!bol2) cnt--;
		}
		if(cur == n) bol1 = 0;
		if(bol1) cur++;
		if(!bol1) cur--;
		if(i && i != n * 2) cout << 0;
		cout << endl;
	}
}