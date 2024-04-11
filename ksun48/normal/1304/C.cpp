#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n;
	cin >> n;
	ll m;
	cin >> m;
	vector<pair<ll, pair<ll, ll> > > s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i].first >> s[i].second.first >> s[i].second.second;
	}
	sort(s.begin(), s.end());
	ll cmin = m;
	ll cmax = m;
	bool works = true;
	ll ct = 0;
	for(int i = 0; i < n; i++){
		cmin -= (s[i].first - ct);
		cmax += (s[i].first - ct);
		ct = s[i].first;
		cmin = max(cmin, s[i].second.first);
		cmax = min(cmax, s[i].second.second);
		if(cmin > cmax) works = false;
	}
	if(works){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}