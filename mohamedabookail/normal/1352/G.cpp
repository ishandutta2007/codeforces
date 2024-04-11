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
		if(n <= 3) { cout << -1 << endl; continue; }
		deque < int > dq;
		dq.push_front(1);
		int flag = 1;
		for (int i = 3; i <= n; i++) {
			if(flag == 1) {
				dq.push_front(i);
				flag *= -1;
			}
			else {
				dq.push_back(i);
				if(i == 4) dq.push_back(2);
				flag *= -1;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << dq[i];
			if(i != n - 1) cout << ' ';
		}
		cout <<  endl;
	}
}