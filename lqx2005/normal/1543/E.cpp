#include<bits/stdc++.h>

using namespace std;

#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define debug(x) cerr << #x <<" " << x << endl
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
const int LG = 16, N = 1 << LG;
int n, V;
int id[N], col[N], vis[N];
int p[N], q[N];
vector<int> g[N];
void divide(int L, int R) {
	if(L == R) return;
	int s = id[L], t = g[s][0];
	int l = 0, r = 0;
	p[0] = s, q[0] = t, vis[s] = vis[t] = 1;
	while(l <= r) {
		int nowa = p[l], nowb = q[l++];
		for(int &v : g[nowa]) if(!vis[v]) vis[v] = 2;
		for(int &v : g[nowb]) {
			if(vis[v]) continue;
			for(int &w : g[v]) {
				if(vis[w] <= 1) continue;
				vis[v] = vis[w] = 1;
				p[++r] = w, q[r] = v;
				break;
			}
		}
	}
	for(int i = 0; i <= r; i++) vis[p[i]] = 1, vis[q[i]] = 2;
	for(int i = L; i <= R; i++) {
		int u = id[i];
		vector<int> nex;
		for(int &v : g[u]) if(vis[u] == vis[v]) nex.push_back(v);
		g[u] = nex;
	}
	for(int i = L; i <= R; i++) vis[id[i]] = 0;
	vector<int> P, Q;
	for(int i = 0; i <= r; i++) P.push_back(p[i]), Q.push_back(q[i]);
	for(int i = 0; i <= r; i++) id[L + i] = p[i];
	divide(L, L + r);
	for(int i = 0; i <= r; i++) {
		vis[id[L + i]] = L + i;
	}
	for(int i = 0; i <= r; i++) id[L + r + 1 + vis[P[i]]] = Q[i];
	for(int i = L; i <= R; i++) vis[id[i]] = 0;
	return;
}

void adde(int u, int v) { g[u].push_back(v); }

void solve() {
	cin >> n;
	V = 1 << n;
	for(int i = 0; i < V; i++) g[i].clear(), id[i] = i;
	int m = n << (n - 1);
	for(int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		adde(u, v), adde(v, u);
	}
	divide(0, V - 1);
	for(int i = 0; i < V; i++) cout << id[i] <<" \n"[i == V - 1];
	if((1 << n) % n) {
		cout << "-1\n";
		return;
	}
	for(int i = 0; i < V; i++) {
		col[id[i]] = 0;
		for(int j = 0; j < n; j++) if((i >> j) & 1) col[id[i]] ^= j;
	}
	for(int i = 0; i < V; i++) cout << col[i] <<" \n"[i == V - 1];
	return;
}

int main() {
	int T;
	for(cin >> T; T--; ) solve();
	return 0;
}