#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
int a[MAXN], ans[MAXN];

int nxt[MAXN], p[MAXN], ranks[MAXN];
void init() {
	REP (i, 0, n) {
		nxt[i] = i - 1;
		p[i] = i;
		ranks[i] = 1;
	}
}
int findSet(int a) {
	if (p[a] == a) return a;
	return p[a] = findSet(p[a]);
}
void unionSet(int a, int b) {
	int pa = findSet(a), pb = findSet(b);
	if (pa == pb) return;
	if (ranks[pa] < ranks[pb]) swap(pa, pb);
	if (ranks[pa] == ranks[pb]) ranks[pa]++;
	p[pb] = pa;
	mnto(nxt[pa], nxt[pb]);
}
int getNext(int a) {
	return nxt[findSet(a)];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) scanf("%d", &a[i]);
		init();
		REP (i, 0, n) {
			int lim = max(0, i - a[i] + 1);
			if (a[i] > 0) {
				ans[i] = 1;
				int cur = i;
				while (getNext(cur) >= lim) {
					int nxt = getNext(cur);
					ans[nxt] = 1;
					unionSet(cur, nxt);
					cur = nxt;
				}
			}
		}
		REP (i, 0, n) {
			printf("%d ", ans[i]);
			ans[i] = 0;
		}
		printf("\n");
	}
	return 0;
}