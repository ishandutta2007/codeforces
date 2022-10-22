#include<bits/stdc++.h>

using namespace std;

#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 5e5 + 10;
int T, n, m, id[N];
vector<int> g[N];
LL c[N];

int cmp(int x, int y) { return g[x] < g[y]; }

void work() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &c[i]), g[i].clear();
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[v].push_back(u);
	}
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		sort(ALL(g[i]));
		if(!g[i].empty()) id[++tot] = i;
	}
	sort(id + 1, id + tot + 1, cmp);
	LL sum = c[id[1]], G = 0;
	for(int i = 2; i <= tot; i++) {
		if(g[id[i - 1]] == g[id[i]]) {
			sum += c[id[i]];
		} else {
			G = __gcd(G, sum);
			sum = c[id[i]];
		}
	}
	G = __gcd(G, sum);
	printf("%lld\n", G);
	return;
}

int main() {
	scanf("%d", &T);
	for(; T--; ) work();
	return 0;
}