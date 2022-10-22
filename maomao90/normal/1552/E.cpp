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
#define MAX 10005
#define MAXN 105

struct thing {
	ii r;
	int c;
	bool operator< (const thing& o) const {
		return r.SE < o.r.SE;
	}
};

int n, k;
int c[MAX];
vii range[MAXN];
bool used[MAXN];
ii ans[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 0, n * k) {
		scanf("%d", &c[i]);
	}
	REP (i, 0, n * k) {
		ii lr;
		if (range[c[i]].empty()) {
			lr = MP(-1, i);
		} else {
			lr = MP(range[c[i]].back().SE, i);
		}
		range[c[i]].pb(lr);
	}
	int num = (n - 1) / (k - 1) + 1;
	REP (i, 1, k) {
		vector<thing> v;
		REP (j, 1, n + 1) {
			v.pb({range[j][i], j});
		}
		sort(ALL(v));
		int ptr = 0;
		REP (j, 0, num) {
			while (ptr < v.size() && used[v[ptr].c]) {
				ptr++;
			}
			if (ptr == v.size()) {
				break;
			}
			ans[v[ptr].c] = (v[ptr].r);
			used[v[ptr].c] = 1;
		}
	}
	REP (i, 1, n + 1) {
		printf("%d %d\n", ans[i].FI + 1, ans[i].SE + 1);
	}
	return 0;
}