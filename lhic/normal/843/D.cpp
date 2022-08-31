#pragma GCC optimize "-O3"
#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXMEM = 400000000;
char mem[MAXMEM];
int mcur;
int gcur;

void *operator new(size_t s) {
	if (mcur + s > MAXMEM)
		mcur = gcur;
	char *ans = &mem[mcur];
	mcur += s;
	return (void *)ans;
}

void operator delete(void *) {}

struct edge {
	int a, b, c, n;
	edge(int A, int B, int C, int N) {
		a = A, b = B, c = C, n = N;
	}
};
const ll INF = 1e16;
const int MAXN = 120000;


int n, m, q;
vector<edge> ed;
vector<int> eds[MAXN];
ll dd[MAXN];
int nw[MAXN];
set<pair<ll, int> > ss;
vector<int> vv[1000100];
int was[MAXN];
int ps[MAXN];

bool cmp(edge a, edge b) {
	return a.a < b.a;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		ed.push_back(edge(a, b, c, i));
	}
	sort(ed.begin(), ed.end(), cmp);
	for (int i = 0; i < m; ++i)
		ps[ed[i].n] = i, eds[ed[i].a].push_back(i);
	fill(dd, dd + n, INF);
	dd[0] = 0;
	ss.insert(make_pair(dd[0], 0));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		for (int e: eds[x]) {
			int u = ed[e].b;
			if (dd[u] > dd[x] + ed[e].c) {
				ss.erase(make_pair(dd[u], u));
				dd[u] = dd[x] + ed[e].c;
				ss.insert(make_pair(dd[u], u));
			}
		}
	}
	gcur = mcur;
	int k = 0;
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			if (k) {
				memset(was, 0, sizeof(was[0]) * n);
				vv[0].push_back(0);
				fill(nw, nw + n, k + 1);
				nw[0] = 0;
				for (int i = 0; i <= k; ++i) {
					for (int j1 = 0; j1 < vv[i].size(); ++j1) {
						int j = vv[i][j1];
						if (was[j])
							continue;
						was[j] = 1;
						dd[j] += i;
						for (int e: eds[j]) {
							int u = ed[e].b;
							if (!was[u] && dd[u] + nw[u] > dd[j] + ed[e].c) {
								nw[u] = dd[j] + ed[e].c - dd[u];
								vv[nw[u]].push_back(u);
							}
						}
					}
					vv[i].clear();
					vv[i].shrink_to_fit();
				}
				k = 0;
			}
			int v;
			scanf("%d", &v);
			--v;
			if (dd[v] >= INF) {
				printf("-1\n");
			}
			else {
				printf("%lld\n", dd[v]);
			}
		}
		else {
			int k1;
			scanf("%d", &k1);
			for (int i = 0; i < k1; ++i) {
				int l;
				scanf("%d", &l);
				--l;
				l = ps[l];
				++ed[l].c;
			}
			k += k1;
		}
	}
    return 0;
}