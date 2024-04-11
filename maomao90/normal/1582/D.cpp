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
int a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			
		}
		if (n % 2 == 1) {
			int tmp = a[2];
			a[2] = -(abs(a[0]) + abs(a[1]));
			a[0] = tmp * (a[0] / abs(a[0]));
			a[1] = tmp * (a[1] / abs(a[1]));
		}
		for (int i = ((n % 2 == 1) ? 3 : 0); i < n; i += 2) {
			assert(i + 1 < n);
			swap(a[i], a[i + 1]);
			a[i + 1] *= -1;
		}
		int sm = 0;
		REP (i, 0, n) {
			sm += a[i];
			printf("%d ", a[i]);
		}
		assert(sm <= 1000000000);
		printf("\n");
	}
	return 0;
}