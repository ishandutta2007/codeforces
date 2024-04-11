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
int a[5], m;

int main() {
	scanf("%d", &t);
	while (t--) {
		REP (i, 0, 3) {
			scanf("%d", &a[i]);
			a[i]--;
		}
		scanf("%d", &m);
		sort(a, a + 3);
		int sub = min(m, a[2] - a[1]);
		m -= sub;
		a[2] -= sub;
		sub = min(m, (a[1] - a[0]) * 2) / 2;
		m -= sub * 2;
		a[1] -= sub;
		a[2] -= sub;
		sub = m / 3;
		m -= sub * 3;
		a[0] -= sub;
		a[1] -= sub;
		a[2] -= sub;
		sort(a, a + 3);
		RREP (i, 2, 2 - m + 1) {
			a[i]--;
		}
		sort(a, a + 3);
		debug("%d %d %d\n", a[0], a[1], a[2]);
		if (a[0] < 0 || a[2] > a[0] + a[1] + 2) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}