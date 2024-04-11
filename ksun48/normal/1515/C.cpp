#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m, x;
	cin >> n >> m >> x;
	cout << "YES" << '\n';
	set<pair<int,int> > h;
	for(int i = 0; i < m; i++) h.insert({0, i});
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		auto [l, d] = *h.begin();
		h.erase(h.begin());
		cout << d+1 << ' ';
		l += a;
		h.insert({l, d});
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}