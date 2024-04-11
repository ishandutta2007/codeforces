#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)3e5 + 10;
const int MAXLOGN = 25;

vi G[MAXN];
vi T[MAXN];
int C[MAXN], cmp;
set<pii> bridges;

int val[MAXN], hi[MAXN], bTime;
int F[MAXN][MAXLOGN], H[MAXN];
int B[MAXN], E[MAXN], L[MAXN];
bool mk[MAXN];

bool isBridge(int u, int v){
	if (u > v) swap(u, v);
	return bridges.count((pii){u, v});
}

void dfsTime(int s, int f){
	val[s] = hi[s] = bTime++;
	bool ok = false;
	for (auto nxt : G[s]){
		if (!val[nxt]){
			dfsTime(nxt, s);
			if(hi[nxt] == val[nxt]){ // s - nxt (is a bridge)
				bridges.insert((pii){min(nxt,s),max(nxt,s)});
			}
		}
		if (f != nxt || ok) hi[s] = min(hi[s], hi[nxt]);
		else ok = true;
	}
}

void setCmp(int s){
	for (auto nxt : G[s]){
		if (C[nxt]) continue;

		if (isBridge(s, nxt)){
			C[nxt] = cmp++;
			T[C[s]].push_back(C[nxt]);
			T[C[nxt]].push_back(C[s]);
		}
		else C[nxt] = C[s];

		setCmp(nxt);
	}
}

void setFather(int s){
	for (auto nxt : T[s]){
		if (H[nxt]) continue;
		F[nxt][0] = s;
		H[nxt] = H[s] + 1;
		setFather(nxt);
	}
}

int lca(int u, int v){
	if (H[v] > H[u]) swap(u, v);
	int d = H[u] - H[v];

	for (int i = 0; d; ++i){
		if (d & (1 << i)){
			d ^= 1 << i;
			u = F[u][i];
		}
	}

	assert(H[u] == H[v]);

	if (u == v) return u;

	for (int i = 20; i >= 0; --i)
		if(F[u][i] != F[v][i])
			u = F[u][i], v = F[v][i];

	return F[u][0] == F[v][0] ? F[u][0] : 0;
}

void dfs(int s){
	mk[s] = true;
	for (auto nxt : T[s]){
		if (mk[nxt]) continue;
		dfs(nxt);
		B[s] += B[nxt];
		E[s] += E[nxt];
		L[s] += L[nxt];
	}

	if (B[s] - L[s] > 0 && E[s] - L[s] > 0){
		cout << "No" << endl;
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bTime = 1;
	for (int i = 1; i <= n; ++i)
		if (!val[i]) dfsTime(i, -1);

	cmp = 1;
	for (int i = 1; i <= n; ++i){
		if (!C[i]){
			C[i] = cmp++;
			setCmp(i);
		}
	}

	for (int i = 1; i < cmp; ++i){
		if (!H[i]){
			H[i] = 1;
			setFather(i);
		}
	}

	for (int i = 1; (1 << i) <= cmp; ++i)
		for (int j = 1; j < cmp; ++j)
			F[j][i] = F[ F[j][i - 1] ][i - 1];

	while (q--){
		int u, v;
		cin >> u >> v;
		u = C[u], v = C[v];
		int l = lca(u, v);
//		cout << u << " " << v << " " << l << endl;

		if (l == 0){
			cout << "No" << endl;
			exit(0);
		}

		B[u]++; E[v]++;
		L[l]++;
	}

	for (int i = 1; i <= n; ++i){
		if (!mk[i]) dfs(i);
	}

	cout << "Yes" << endl;

	return 0;
}