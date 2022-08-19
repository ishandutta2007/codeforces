#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int v = 1;
	for(int j = 0; j < n; j++) v -= a[v];
	vector<int> ans;
	int w = v;
	while(true){
		ans.push_back(v);
		v -= a[v];
		if(v == w) break;
	}
	cout << ans.size() << '\n';
	for(int x : ans) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}