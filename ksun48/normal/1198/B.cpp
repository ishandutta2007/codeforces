#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll res = 0;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<pair<ll, ll> > events;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		events.emplace_back(i, a[i]);
	}
	vector<ll> ans(n, -2);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll p, amt;
		int type;
		cin >> type;
		if(type == 1){
			cin >> p >> amt;
			p -= 1;
		} else {
			p = -1;
			cin >> amt;
		}
		events.emplace_back(p, amt);
	}
	reverse(events.begin(), events.end());
	ll rmax = -1;
	for(pair<ll, ll> e : events){
		if(e.first == -1){
			rmax = max(rmax, e.second);
		} else {
			if(ans[e.first] == -2){
				ans[e.first] = max(rmax, e.second);
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}