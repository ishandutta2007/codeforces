/**
 *    author:  Mohamed.Abo_Okail
 *    created: 31/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n, q; cin >> n >> q;
	deque <ll> dq(n);
	vector<pair <ll, ll>> ans;
	ll mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> dq[i];
		if(mx < dq[i]) {
			mx = dq[i];
		}
	}
	while(mx != dq[0]) {
		ll a = dq[0], b = dq[1];
		ans.push_back({a, b});
		dq.pop_front();
		dq.pop_front();
		if(a > b) {
			dq.push_front(a);
			dq.push_back(b);
		}
		else {
			dq.push_front(b);
			dq.push_back(a);
		}
	} dq.pop_front();
	while(q--) {
		ll a; cin >> a; a--;
	    if(a < ans.size()) {
			cout << ans[a].first << ' ' << ans[a].second << endl;
		}
		else {
		    a -= ans.size();
			cout << mx << ' ' << dq[a % (n - 1)] << endl;
		}
	}
}