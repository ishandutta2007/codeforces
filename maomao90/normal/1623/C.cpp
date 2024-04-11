// time-limit: 1000
// problem-url: https://codeforces.com/contest/1623/problem/C

// he refreshes my soul. He guides me along the right
// paths for his name's sake
// Psalms 23:3
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

int t;
int n;
int h[MAXN], th[MAXN];

bool isPos(int x) {
	REP (i, 0, n) {
		th[i] = h[i];
	}
	RREP (i, n - 1, 2) {
		if (th[i] < x) {
			return 0;
		}
		int d = (th[i] - x) / 3 * 3;
		mnto(d, h[i]);
		d /= 3;
		if (x == 15) {
			debug(" %d: %d %d\n", i, th[i], d);
		}
		th[i] -= 3 * d;
		th[i - 1] += d;
		th[i - 2] += 2 * d;
	}
	REP (i, 0, n) {
		if (th[i] < x) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &h[i]);
		}
		int lo = 0, hi = INF, mid;
		while (lo < hi) {
			mid = lo + hi + 1 >> 1;
			if (isPos(mid)) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		printf("%d\n", lo);
	}
	return 0;
}