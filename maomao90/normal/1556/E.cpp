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
#define MAXN 200005
#define MAXL 20

int n, q;
int a[MAXN], b[MAXN];
ll d[MAXN];
ll mn[MAXL][MAXN], mx[MAXL][MAXN];

ll getmn(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}
ll getmx(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}

int main() {
	scanf("%d%d", &n, &q);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	REP (i, 1, n + 1) {
		scanf("%d", &b[i]);
	}
	REP (i, 1, n + 1) {
		d[i] = b[i] - a[i];
		d[i] += d[i - 1];
		mn[0][i] = mx[0][i] = d[i];
	}
	REP (k, 1, MAXL) {
		REP (i, 1, n - (1 << k - 1) + 1) {
			mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << k - 1)]);
			mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + (1 << k - 1)]);
		}
	}
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		if (d[r] - d[l - 1] != 0) {
			printf("-1\n");
		} else {
			ll mn = getmn(l, r);
			ll mx = getmx(l, r);
			mn -= d[l - 1];
			mx -= d[l - 1];
			if (mn < 0) {
				printf("-1\n");
			} else {
				printf("%lld\n", mx);
			}
		}
	}
	return 0;
}