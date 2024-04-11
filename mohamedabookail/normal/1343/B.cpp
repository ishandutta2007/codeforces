/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define line "\n"
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
		ll n; cin >> n;
		vector < ll > a(n / 2), b(n / 2);
		int cnt = 2, sum1 = 0, sum2 = 0;
		for (int i = 0; i < n / 2; i++) {
			a[i] = cnt;
			sum1 += cnt;
			cnt += 2;
		}
		cnt = 1;
		for (int i = 0; i < n / 2 - 1; i++) {
			b[i] = cnt;
			sum2 += cnt;
			cnt += 2;
		}
		if((sum1 - sum2) > 0 && (sum1 - sum2) % 2 != 0) {
			b[n / 2 - 1] = sum1 - sum2;
			cout << "YES" << endl;
			for (int i = 0; i < n / 2; i++) {
				cout << a[i] << ' ';
			}
			for (int i = 0; i < n / 2; i++) {
				cout << b[i] << ' ';
			}
			cout << endl;
		}
		else cout << "NO" << endl;
	}
}