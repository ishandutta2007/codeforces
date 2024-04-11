#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int n, m[2];
vii ans;

struct dsu {
	int p[MAXN], rnk[MAXN], mex[MAXN];
	void init() {
		REP (i, 0, n + 5) {
			p[i] = i;
			rnk[i] = 1;
			mex[i] = 1;
		}
		mex[1] = 2;
	}
	int find(int i) {
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	bool join(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa == pb) return 0;
		if (rnk[pa] < rnk[pb]) swap(pa, pb);
		if (rnk[pa] == rnk[pb]) rnk[pa]++;
		p[pb] = pa;
		mex[pa] = max(mex[pa], mex[pb]);
		while (same(mex[pa], a)) {
			mex[pa]++;
		}
		return 1;
	}
	int get(int i) {
		return mex[find(i)];
	}
} dsus[2];

int main() {
	scanf("%d%d%d", &n, &m[0], &m[1]);
	REP (i, 0, 2) {
		dsus[i].init();
		REP (j, 0, m[i]) {
			int u, v; scanf("%d%d", &u, &v);
			dsus[i].join(u, v);
		}
	}
	REP (u, 1, n + 1) {
		int v = max(dsus[0].get(u), dsus[1].get(u));
		while (v < u) {
			dsus[0].join(u, v);
			dsus[1].join(u, v);
			ans.pb(MP(u, v));
			v = max(dsus[0].get(u), dsus[1].get(u));
		}
	}
	printf("%d\n", (int) ans.size());
	for (auto [i, j] : ans) {
		//i = mp[i], j = mp[j];
		printf("%d %d\n", i, j);
	}
	return 0;
}