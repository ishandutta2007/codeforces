#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	int n;
	cin >> n;
	vector<ll> w(n);
	for(ll& a : w) cin >> a;
	vector<int> deg(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[u]++;
		deg[v]++;
	}
	vector<ll> stuff;
	for(int i = 0; i < n; i++){
		for(int r = 0; r < deg[i]-1; r++){
			stuff.push_back(w[i]);
		}
	}
	sort(stuff.rbegin(), stuff.rend());
	ll tw = 0;
	for(int i = 0; i < n; i++) tw += w[i];
	cout << tw;
	for(ll x : stuff){
		tw += x;
		cout << ' ' << tw;
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}