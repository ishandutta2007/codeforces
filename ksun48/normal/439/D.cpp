#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	using ll = long long;
	vector<ll> a(n), b(m);
	for(ll& x : a) cin >> x;
	for(ll& x : b) cin >> x;
	vector<pair<ll, ll> > f;
	for(ll x : a) f.push_back({x, 0});
	for(ll x : b) f.push_back({x, 1});
	sort(f.begin(), f.end());
	ll lasum = 0;
	ll lacnt = 0;
	ll rbsum = 0;
	ll rbcnt = m;
	for(ll x : b) rbsum += (x - f.front().first);
	ll ans = rbsum;
	for(int i = 0; i + 1 < (int)f.size(); i++){
		if(f[i].second == 0){
			lacnt += 1;
		}
		if(f[i].second == 1){
			rbcnt -= 1;
		}
		lasum += lacnt * (f[i+1].first - f[i].first);
		rbsum -= rbcnt * (f[i+1].first - f[i].first);
		ans = min(ans, lasum + rbsum);
	}
	cout << ans << '\n';
}