#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10;
int n, m, k;
int mt[N], deg[N], ans[N], tot = 0;
vector<int> g[N];
vector<int> r[N];
string p[N], s[N];
map<string, int> id;

void adde(int u, int v) {
	g[u].push_back(v);
	deg[v]++;
	return;
}

void topsort() {
	queue<int> q;
	for(int i = 1; i <= n; i++) if(!deg[i] && id.count(p[i])) q.push(i);
	while(!q.empty()) {
		int u = q.front();
		ans[++tot] = u;
		q.pop();
		for(int i = 0; i < (int)g[u].size(); i++) {
			int v = g[u][i];
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	return;
}

int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= m; i++) cin >> s[i] >> mt[i];
	for(int i = 1; i <= m; i++) {
		if(id.count(p[mt[i]]) && id[p[mt[i]]] != mt[i]) return printf("NO\n"), 0;
		id[p[mt[i]]] = mt[i];
	}
	for(int i = 1; i <= n; i++) {
		if(!id.count(p[i])) {
			id[p[i]] = i;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(i != id[p[i]]) r[id[p[i]]].push_back(i);
	}
	for(int i = 1; i <= m; i++) {
		vector<int> nx;
		for(int msk = 0; msk < (1 << k); msk++) {
			string now = "";
			for(int j = 0; j < k; j++) {
				if((msk >> j) & 1) now += '_';
				else now += s[i][j];
			}
			if(id.count(now)) nx.push_back(id[now]);
		}
		int fg = 0;
		for(int j = 0; j < (int)nx.size(); j++) {
			if(nx[j] == mt[i]) {
				fg = 1;
				continue;
			}
			adde(mt[i], nx[j]);
		}
		if(!fg) return printf("NO\n"), 0;
	}
	topsort();
	if(tot != (int)id.size()) return printf("NO\n"), 0;
	printf("YES\n");
	for(int i = 1; i <= tot; i++) {
		printf("%d ", ans[i]);
		for(int j = 0; j < (int) r[ans[i]].size(); j++) printf("%d ", r[ans[i]][j]);
	}
	printf("\n");
	return 0;
}