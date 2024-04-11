#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	for(int i = 0; i < n; i++){
		cin >> q[i];
		q[i]--;
	}
	vector<int> perm(n);
	for(int i = 0; i < n; i++){
		perm[p[i]] = q[i];
	}
	vector<int> vis(n, 0);
	int odd_cycles = 0;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		int cur = i;
		int len = 0;
		while(!vis[cur]){
			len++;
			vis[cur] = 1;
			cur = perm[cur];
		}
		if(len & 1) odd_cycles++;
	}
	int e = (n - odd_cycles) / 2;
	using ll = int64_t;
	ll ans = ll(n-1 + n-1 - 2*(e-1)) * ll(e);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}