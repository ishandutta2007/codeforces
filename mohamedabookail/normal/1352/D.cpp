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
		deque < int > dq(n);
		ll ans1 = 0, ans2 = 0, cur1 = 0, cur2 = 0, cnt = 0, flag = 1;
		for (int i = 0; i < n; i++) {
			cin >> dq[i];
		}
		while(!dq.empty()) {
			if(flag == 1) {
				cur1 += dq.front();
				dq.pop_front();
				if(cur1 > cur2 || dq.empty()) {
					ans1 += cur1;
					cur2 = 0;
					flag *= -1;
					cnt++;
				}
			}
			else {
				cur2 += dq.back();
				dq.pop_back();
				if(cur2 > cur1 || dq.empty()) {
					ans2 += cur2;
					cur1 = 0;
					flag *= -1;
					cnt++;
				}
			}
		}
		cout << cnt << ' ' << ans1 << ' ' << ans2 << endl;
	}
}