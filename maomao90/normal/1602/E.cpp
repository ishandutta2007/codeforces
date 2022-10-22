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
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 2000008

int t;
int n, m;
int a[MAXN], b[MAXN];
vi mp[MAXN];
ll ans;

int fw[MAXN];
void incre(int i, int x) {
	for (; i <= n + m; i += i & -i) fw[i] += x;
}
int qsm(int i) {
	int res = 0;
	for (; i >= 1; i -= i & -i) res += fw[i];
	return res;
}
int qsm(int s, int e) {
	return qsm(e) - qsm(s - 1);
}

void dnc(int l, int r, int optl, int optr) {
	if (l > r) return;
	int mn = INF, opt = -1;
	int mid = l + r >> 1;
	int cur = 0;
	REP (i, optl, optr + 1) {
		cur += b[mid] > a[i];
	}
	REP (i, optl, optr + 2) {
		if (mnto(mn, cur)) {
			opt = i;
		}
		cur -= b[mid] > a[i];
		cur += b[mid] < a[i];
	}
	mp[opt].pb(mid);
	dnc(l, mid - 1, optl, opt - 1);
	dnc(mid + 1, r, opt, optr);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n + 5) {
			mp[i].clear();
		}
		vii dis;
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			dis.pb(MP(a[i], i));
		}
		REP (i, 0, m) {
			scanf("%d", &b[i]);
			dis.pb(MP(b[i], i + n));
		}
		sort(ALL(dis));
		int prv = -1, cnt = 0;
		REP (i, 0, dis.size()) {
			if (dis[i].FI != prv) {
				cnt++;
				prv = dis[i].FI;
			}
			if (dis[i].SE < n) {
				a[dis[i].SE] = cnt;
			} else {
				b[dis[i].SE - n] = cnt;
			}
		}
		sort(b, b + m);
		REP (i, 0, n) {
			debug("%d ", a[i]);
		}
		debug("\n");
		REP (i, 0, m) {
			debug("%d ", b[i]);
		}
		debug("\n");
		dnc(0, m - 1, 0, n - 1);
		vi v;
		REP (i, 0, n + 1) {
			sort(ALL(mp[i]));
			for (int j : mp[i]) {
				v.pb(b[j]);
			}
			if (i != n) v.pb(a[i]);
		}
		assert(v.size() == n + m);
		REP (i, 0, n + m) {
			debug("%d ", v[i]);
		}
		debug("\n");
		ans = 0;
		REP (i, 0, n + m + 5) {
			fw[i] = 0;
		}
		REP (i, 0, n + m) {
			ans += qsm(v[i] + 1, n + m);
			incre(v[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}