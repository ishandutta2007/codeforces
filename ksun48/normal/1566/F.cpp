#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	vector<pair<ll, ll> > segs(m);
	for(auto& [x, y] : segs) cin >> x >> y;
	for(ll x : a) segs.push_back({x, x});
	for(auto& [x, y] : segs){
		x = -x;
		swap(x, y);
	}
	sort(segs.begin(), segs.end());	
	for(auto& [x, y] : segs){
		swap(x, y);
		x = -x;
	}
	{
		vector<pair<ll, ll> > nsegs;
		for(auto [x, y] : segs){
			if(nsegs.empty() || x > nsegs.back().first){
				nsegs.push_back({x, y});
			}
		}
		segs = nsegs;
	}
	a.push_back(-1e16);
	a.push_back(1e16);
	sort(a.begin(), a.end());
	ll b0 = 0;
	ll b1 = 0;
	int cur = 0;
	for(int i = 1; i < (int)a.size(); i++){
		vector<ll> st, en;
		st.push_back(a[i-1]);
		while(cur < (int)segs.size() && segs[cur].second <= a[i]){
			if(segs[cur].second < a[i] && segs[cur].first > a[i-1]){
				st.push_back(segs[cur].first);
				en.push_back(segs[cur].second);
			}
			cur++;
		}
		en.push_back(a[i]);
		ll n0 = 1e18;
		ll n1 = 1e18;
		for(int j = 0; j < (int)st.size(); j++){
			n0 = min(n0, b0 + (st[j] - a[i-1]) + 2 * (a[i] - en[j]));
			n0 = min(n0, b1 + 2 * (st[j] - a[i-1]) + 2 * (a[i] - en[j]));
			n1 = min(n1, b0 + (st[j] - a[i-1]) + (a[i] - en[j]));
			n1 = min(n1, b1 + 2 * (st[j] - a[i-1]) + (a[i] - en[j]));
		}
		b0 = n0;
		b1 = n1;
	}
	cout << min(b0, b1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}