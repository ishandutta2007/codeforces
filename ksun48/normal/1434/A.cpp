#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	vector<ll> a(6);
	for(ll& x : a) cin >> x;
	int n;
	cin >> n;
	vector<ll> b(n);
	for(ll& x : b) cin >> x;
	sort(a.rbegin(), a.rend());
	set<pair<ll, int> > cur;
	for(int i = 0; i < n; i++){
		cur.insert({b[i] - a[0], i});
	}
	vector<int> which(n, 0);
	ll ans = 1e18;
	while(true){
		ans = min(ans, (*cur.rbegin()).first - (*cur.begin()).first);
		int f = (*cur.begin()).second;
		cur.erase(cur.begin());
		which[f]++;
		if(which[f] == 6) break;
		cur.insert({b[f] - a[which[f]], f});
	}
	cout << ans << '\n';
}