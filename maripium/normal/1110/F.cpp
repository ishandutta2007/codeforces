#include <bits/stdc++.h>
using namespace std;

const int N = 1000500;
const long long inf = 1e18;

int n, q;
vector<pair<int,int>> g[N];
long long dep[N];
int now;
int id[N], tin[N], val[N], tot;
int rmq[20][N], len[N];
bool del[N];
int child[N];
int par[N];
int ver[N];
vector<pair<int,long long>> vals[N];
vector<pair<int,int>> buf[N];
long long ans[N];
int ll[N];

long long get(vector<pair<int,long long>> vals, int l) {
	auto it = lower_bound(vals.begin(), vals.end(), make_pair(l, 0LL));
	if (it == vals.end()) {
		return inf;
	} else {
		return it->second;
	}
}

void add(vector<pair<int, long long>> &vals, int r,long long val) {
	while (vals.size() && vals.back().second > val) {
		vals.pop_back();
	}
	vals.push_back(make_pair(r, val));
}

void dfs(int u,int p) {
   id[++tot] = u;
   val[tot] = tot;
   tin[u] = tot;
   ++now;
   bool leaf = true;
   for (auto e : g[u]) {
   	if (e.first != p) {
   		leaf = false;
		}
	}
	if (leaf) {
		ver[now] = u;
	}
   for (auto e : g[u]) {
      int v = e.first;
      int w = e.second;
      if (v == p) {
         continue;
      }
      dep[v] = dep[u] + w;
      dfs(v, u);
      val[++tot] = tin[u];
   }
}

void prep() {
    for (int i = 1; i <= tot; ++i) {
        rmq[0][i] = val[i];
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= tot; ++j) {
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
        }
    }
    for (int i = 2; i <= tot; ++i) {
        len[i] = len[i >> 1] + 1;
    }
}
int lca(int u,int v) {
    if (tin[u] > tin[v]) {
        swap(u, v);
    }
    int l = tin[u], r = tin[v];
    int len = ::len[r - l + 1];
    return id[min(rmq[len][l], rmq[len][r - (1 << len) + 1])];
}
long long dist(int u,int v) {
    return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}
void dfs2(int u,int p) {
    child[u] = 1;
    for (auto e : g[u]) {
        int v = e.first;
        if (v == p || del[v]) {
            continue;
        }
        dfs2(v, u);
        child[u] += child[v];
    }
}
int find(int u,int p,int r) {
    for (auto e : g[u]) {
        int v = e.first;
        if (v == p || del[v]) {
            continue;
        }
        if (child[v] * 2 >= child[r]) {
            return find(v, u, r);
        }
    }
    return u;
}
void build(int u,int p) {
    dfs2(u, -1);
    u = find(u, u, u);
    par[u] = p;
    del[u] = true;
    for (auto e : g[u]) {
        int v = e.first;
        if (del[v]) {
            continue;
        }
        build(v, u);
    }
}

int main() {
	scanf("%d %d", &n, &q);
	for (int u = 2; u <= n; ++u) {
		int v, w;
		scanf("%d %d", &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	dfs(1, -1);
	prep();
	build(1, 0);
	for (int i = 1; i <= q; ++i) {
		int x, r;
		scanf("%d %d %d", &x, ll + i, &r);
		buf[r].push_back(make_pair(x, i));
	}
	for (int r = 1; r <= n; ++r) {
		if (ver[r]) {
			int u = ver[r];
			int v = u;
			while (v) {
				add(vals[v], r, dist(u, v));
				v = par[v];
			}
		}
		for (auto it : buf[r]) {
			int u = it.first;
			int id = it.second;
			ans[id] = inf;
			int v = u;
			while (v) {
				ans[id] = min(ans[id], dist(u, v) + get(vals[v], ll[id]));
				v = par[v];
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		printf("%lld\n", ans[i]);
	} 
}