#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100100;
const int maxl = 21;
const int64 mod = 1000000007;

vector<pii> ady[maxn];
int tot[maxn];
int upd[2][maxn];
int mode[maxn];
int f[maxn][maxl];
int h[maxn];
int64 ans;

void dfs(int s){
	for (auto nxt : ady[s]){
		if (h[nxt.first]) continue;
		h[nxt.first] = h[s] + 1;
		f[nxt.first][0] = s;
		mode[nxt.first] = nxt.second;
		dfs(nxt.first);
	}
}

int lca(int a, int b){
	if (h[a] < h[b]) swap(a, b);

	int d = h[a] - h[b];
	for (int i = 0; d; ++i){
		if (d & (1 << i))
		{
			a = f[a][i];
			d ^= (1 << i);
		}
	}

	if (a == b) return a;

	for (int i = maxl - 1; i >= 0; --i){
		if (f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	}

	return f[a][0];
}

void update(int u, int v){
	int l = lca(u, v);
	upd[0][u]++;
	upd[0][l]--;
	upd[1][v]++;
	upd[1][l]--;
}

int64 modexp(int64 v, int64 p){
	if (p == 0) return 1;
	int64 ans = modexp(v * v % mod, p / 2);
	if (p & 1) ans = ans * v % mod;
	return ans;
}

int64 calc(int64 v){
	int64 ans = modexp(2, v) - 1;
	if (ans == -1) ans = mod - 1;
	return ans;
}

void dfs1(int s){
	for (auto nxt : ady[s])
		if (h[nxt.first] == h[s] + 1)
		{
			dfs1(nxt.first);
			upd[0][s] += upd[0][nxt.first];
			upd[1][s] += upd[1][nxt.first];
		}

	// cout << s << " " << mode[s] << " " << upd[0][s] << " " << upd[1][s] << endl;

	int64 cur = 0;
	if (mode[s] == 1) cur = calc(upd[0][s]);
	else if (mode[s] == -1) cur = calc(upd[1][s]);

	ans = (ans + cur) % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		ady[u].push_back(pii(v, w));
		ady[v].push_back(pii(u, -w));
	}

	h[1] = 1;
	f[1][0] = 0;
	dfs(1);

	for (int i = 1; (1 << i) <= n; ++i)
		for (int j = 1; j <= n; ++j){
			f[j][i] = f[f[j][i - 1]][i - 1];
		}

	int cur = 1;
	int q; cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int v; cin >> v;
		update(cur, v);
		cur = v;
	}

	ans = 0;
	dfs1(1);

	cout << ans << endl;


	return 0;
}