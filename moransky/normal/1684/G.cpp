// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1005, M = N * N + N, INF = 1e9;


// 
namespace MF{
    int n, m, s, t, pre[N], cur[N], q[N];
    LL res, maxflow, d[N];

    int head[N], numE = 1;

    struct E{
        int next, v, w;
    } e[M << 1];

    void inline add(int u, int v, int w) {
        e[++numE] = (E) { head[u], v, w };
        head[u] = numE;
    }

    void inline init(int v, int a, int b) {
        for (int i = 1; i <= n; i++) head[i] = 0;
        numE = 1;
        n = v, s = a, t = b;
    }

    bool inline bfs() {
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; i++) d[i] = 0;
        q[++tt] = s, d[s] = 1, cur[s] = head[s];
        while (hh <= tt) {
            int u = q[hh++];
            for (int i = head[u]; i; i = e[i].next) {
                int v = e[i].v;
                if (!d[v] && e[i].w) {
                    cur[v] = head[v];
                    q[++tt] = v, d[v] = d[u] + 1;
                    if (v == t) return true;
                }
            }
        }
        return false;
    }

    LL inline dinic(int u, LL flow) {
        if (u == t) return flow;
        LL rest = flow;
        for (int i = cur[u]; i && rest; i = e[i].next) {
            cur[u] = i;
            int v = e[i].v;
            if (e[i].w && d[v] == d[u] + 1) {
                int k = dinic(v, min((LL)e[i].w, rest));
                if (!k) d[v] = 0;
                rest -= k, e[i].w -= k, e[i ^ 1].w += k;
            }
        }
        return flow - rest;
    }
    void inline addE(int u, int v, int w) {
        add(u, v, w); add(v, u, 0);
    }
    LL inline work() {
        maxflow = 0;
        while (bfs()) 
            while (res = dinic(s, INF)) maxflow += res;
        return maxflow;
    }
}

int n, m, a[N], b[N], t1, c[N], t2, tot, z[N], len;

struct Ed{
	int u, v, id;
} g[N * N];

int ret;

vector<int> d[N];

map<int, int> cnt;

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]), cnt[a[i]]++;
    sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (a[i] * 3ll > m) {
			b[++t1] = a[i];
		} else {
			c[++t2] = a[i];
		}
	}
	int S = t1 + t2 + 1, T = t1 + t2 + 2;
	MF::init(T, S, T);
	for (int i = 1; i <= t1; i++) MF::addE(S, i, 1);
	for (int i = 1; i <= t2; i++) MF::addE(i + t1, T, 1);
		
	for (int i = 1; i <= t1; i++) {
		for (int j = 1; j <= t2; j++) {
			int u = b[i], v = c[j];
			if (2 * u + v <= m && u % v == 0) {
				MF::addE(i, j + t1, 1);
				g[++tot] = (Ed) { u, v, MF::numE };
			}
		}
	}
	int ans = MF::work();
	if (ans != t1) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= tot; i++) {
		if (MF::e[g[i].id].w) {
			++ret;
			int u = g[i].u, v = g[i].v;
			d[ret].pb(2 * u + v);
			d[ret].pb(u + v);
			cnt[u]--;
			cnt[v]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i]]) {
			cnt[a[i]]--;
			assert(a[i] * 3ll <= m);
			++ret;
			d[ret].pb(3 * a[i]);
			d[ret].pb(2 * a[i]);
		}
	}
	printf("%d\n", ret);
	for (int i = 1; i <= ret; i++) {
		for (int v: d[i]) printf("%d ", v);
		puts("");
	}

	for (int i = 1; i <= ret; i++) {
		int a = d[i][0], b = d[i][1];
		while (b) {
			int r = a % b;
			if (r) z[++len] = r;
			a = b, b = r;
		}
	}
	// cout << len << endl;
	// for (int i = 1; i <= len; i++) cout << z[i] << " ";
	// cout << endl;
	sort(z + 1, z + 1 + len);
	assert(len == n);
	for (int i = 1; i <= n; i++) assert(z[i] == a[i]);
    return 0;
}