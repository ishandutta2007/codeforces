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
#define MAXN 1000005
#define MAXA 8200

int n;
int a[MAXN];
vi up[MAXA];
int r[MAXA];
bool pos[MAXA];
vi ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
	}
	pos[0] = 1;
	REP (i, 0, MAXA) {
		up[i].pb(0);
		r[i] = MAXA - 1;
	}
	REP (i, 0, n) {
		for (int j : up[a[i]]) {
			int x = a[i] ^ j;
			pos[x] = 1;
			while (r[x] > a[i]) {
				up[r[x]].pb(x);
				r[x]--;
			}
		}
		up[a[i]].clear();
	}
	REP (i, 0, MAXA) {
		if (pos[i]) ans.pb(i);
	}
	printf("%d\n", (int) ans.size());
	for (int i : ans) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}