#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;

const LL MAXN = 610000;

LL p2[MAXN];

void init(){
	p2[0] = 1;
	for(int i = 1; i < MAXN; i++){
		p2[i] = (p2[i-1] * 2) % MOD;
	}
}

vector<vector<int> > edges;
vector<int> col;
int ok;
int cnta;
int cntb;
void dfs(int v, int color){
	if(col[v] == color) return;
	if(col[v] != 0){
		ok = 0;
		return;
	}
	col[v] = color;
	if(color == 1){
		cnta++;
	} else {
		cntb++;
	}
	for(int a : edges[v]){
		dfs(a, -color);
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n, m;
		cin >> n >> m;
		edges.clear();
		edges.resize(n);
		col.clear();
		col.resize(n, 0);
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		LL ans = 1;
		for(int i = 0; i < n; i++){
			if(col[i] == 0){
				ok = 1;
				cnta = cntb = 0;
				dfs(i, 1);
				ans = (ans * (p2[cnta] + p2[cntb])) % MOD;
				if(!ok){
					ans = 0;
				}
			}
		}
		ans %= MOD;
		if(ans < 0) ans += MOD;
		cout << ans << '\n';
	}
}