// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5, S = 6, INF = (2e9) + 1, B = 325;

int n, m, id, len, pos[N * 5];

map<int, int> M;

int inline get(int x) {
	if (M.count(x)) return M[x];
	return M[x] = ++id;
}

vector<int> e[N * 5];

bitset<N> b, c[B + 1];

struct E{
	int v[5], w;
	bool operator < (const E &b) const {
		return w < b.w;
	}
} a[N];

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			read(a[i].v[j]);
		}		
		read(a[i].w);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			a[i].v[j] = get(a[i].v[j]);
			e[a[i].v[j]].pb(i);
		}
	}
	for (int i = 1; i <= id; i++) {
		if (e[i].size() <= B) {
			
		} else {
			++len;
			pos[i] = len;
			c[len].reset();
			c[len].flip();
			for (int u: e[i]) {
				c[len][u] = 0;
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		b.reset();
		b.flip();
		b[0] = 0;
		b[i] = 0;
		for (int j = 0; j < 5; j++) {
			int o = a[i].v[j];
			if (e[o].size() <= B) {
				for (int v: e[o])
					b[v] = 0;
			} else {
				b &= c[pos[o]];
			}
		}
		int p = b._Find_first();
		if (p <= n) chkMin(ans, a[i].w + a[p].w);
	}
	if (ans == INF) ans = -1;
	printf("%d\n", ans);
    return 0;
}