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
#define LINF 2000000000000000005
#define MOD 1000000007
#define MAXN 200005

struct dragon {
	ll x, y;
	int id;
	bool operator< (const dragon& o) const {
		return x < o.x;
	}
};

int n;
ll a[MAXN];
int m;
dragon d[MAXN];
ll sm;
ll ans[MAXN];

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%lld", &a[i]);
		sm += a[i];
	}
	scanf("%d", &m);
	REP (i, 0, m) {
		scanf("%lld%lld", &d[i].x, &d[i].y);
		d[i].id = i;
		ans[i] = LINF;
	}
	sort(d, d + m);
	sort(a, a + n);
	int ptr = 0;
	REP (i, 0, m) {
		while (ptr < n && d[i].x > a[ptr]) {
			ptr++;
		}
		REP (j, ptr - 1, ptr + 1) {
			if (j < 0 || j >= n) continue;
			mnto(ans[d[i].id], max(0ll, d[i].x - a[j]) + 
					max(0ll, d[i].y - (sm - a[j])));
		}
	}
	REP (i, 0, m) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}