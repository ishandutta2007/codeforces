#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;

map<string,int> mp;
int n,m,k;
int par[N];
int mn[N];
int a[N];

int anc(int u) {
	return par[u] == u ? u : par[u] = anc(par[u]);
}

void join(int u,int v) {
	u = anc(u); v = anc(v);
	if (u == v) return;
	mn[u] = min(mn[u],mn[v]);
	par[v] = u;
}

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> k >> m;
	for (int i = 1;i <= n;++i) {
		string s;	cin >> s;
		mp[s] = i;
	}
	for (int i = 1;i <= n;++i) par[i] = i;
	for (int i = 1;i <= n;++i) cin >> mn[i];
	for (int i = 0;i < k;++i) {
		int x;	cin >> x;
		for (int j = 0;j < x;++j) cin >> a[j];
		for (int j = 0;j < x;++j) join(a[0],a[j]);
	}
	
	int ans = 0;
	for (int i = 0;i < m;++i) {
		string s;	cin >> s;
		ans += mn[anc(mp[s])];
	}
	cout << ans << endl;
	//for (int i = 1;i <= n;++i) cout << anc(i) << ' ';
}