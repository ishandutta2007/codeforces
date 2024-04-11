#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll ceil(ll a, ll b){
	assert(a >= 0);
	assert(b > 0);
	return (a + b - 1) / b;
}
ll floor(ll a, ll b){
	assert(a >= 0);
	assert(b > 0);
	return a / b;
}

void solve(){
	ll n, m;
	cin >> n >> m;
	map<ll, ll> delta;
	vector<pair<ll, ll> > days(n);
	for(int i = 0; i < n; i++){
		ll x, p;
		cin >> x >> p;
		days[i] = {x, p};
	}
	for(auto [x, p] : days){
		delta[x - p] += 1;
		delta[x] -= 2;
		delta[x + p] += 1;
	}
	ll ploc = -ll(1e10);
	ll px = 0;
	ll pslope = 0;
	vector<pair<ll, ll> > polyline;
	for(auto [loc, f] : delta){
		px += (loc - ploc) * pslope;
		pslope += f;
		ploc = loc;
		polyline.push_back({loc, px});
	}
	assert(px == 0);
	assert(pslope == 0);
	ll sum_min =  ll(-1e17);
	ll diff_min = ll(-1e17);
	for(auto [x, y] : polyline){
		if(y > m){
			sum_min = max(sum_min, y - m + x);
			diff_min = max(diff_min, y - m - x);
		}
	}
	// for(int i = 1; i < (int)polyline.size(); i++){
	// 	auto [x1, y1] = polyline[i-1];
	// 	auto [x2, y2] = polyline[i];
	// 	if((y1 > m) == (y2 > m)) continue;
	// 	if(y1 > m && y2 <= m){
	// 		ll x = x1 + ceil((y1 - m) * (x2 - x1), y1 - y2);
	// 		ll y = m;
	// 		sum_min = max(sum_min, y - m + x);
	// 		diff_min = max(diff_min, y - m - x);
	// 	} else if(y1 <= m && y2 > m){
	// 		ll x = x1 + floor((y2 - m) * (x2 - x1), y2 - y1);
	// 		ll y = m;
	// 		sum_min = max(sum_min, y - m + x);
	// 		diff_min = max(diff_min, y - m - x);
	// 	}
	// }
	for(auto [x, p] : days){
		cout << int(p + x >= sum_min && p - x >= diff_min);
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}