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
#define MAXN 30005
#define MAXL 29

int n, k;
int aor[MAXN], aand[MAXN];
int a[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 1, n) {
		int f = 1, s = i + 1;
		printf("or %d %d\n", f, s);
		fflush(stdout);
		scanf("%d", &aor[i]);
	}
	REP (i, 1, n) {
		int f = 1, s = i + 1;
		printf("and %d %d\n", f, s);
		fflush(stdout);
		scanf("%d", &aand[i]);
	}
	printf("and 2 3\n");
	fflush(stdout);
	int sp; scanf("%d", &sp);
	RREP (k, MAXL, 0) {
		bool allor = 1, alland = 1;
		bool oneor = 0, oneand = 0;
		REP (i, 1, n) {
			if ((aor[i] & (1 << k))) {
			} else {
				// all or is true
				allor = 0;
				// at least one or false -> 0
				oneor = 1;
			}
			if (!(aand[i] & (1 << k))) {
			} else {
				alland = 0;
				// at least 1 and true -> 1
				oneand = 1;
			}
		}
		if (oneand) {
			a[0] |= 1 << k;
		} else if (oneor) {

		} else if (!(sp & (1 << k))) {
			a[0] |= 1 << k;
		}
	}
	debug("%d\n", a[0]);
	RREP (k, MAXL, 0) {
		REP (i, 1, n) {
			if (aand[i] & (1 << k)) {
				a[i] |= 1 << k;
			} else if (!(aor[i] & (1 << k))) {

			} else if (!(a[0] & (1 << k))) {
				a[i] |= 1 << k;
			}
		}
	}
	REP (i, 0, n) {
		debug("%d: %d\n", i, a[i]);
	}
	nth_element(a, a + k - 1, a + n);
	printf("finish %d\n", a[k - 1]);
	fflush(stdout);
	return 0;
}

/*
   3 1
   6
   7
   2
   0
   */