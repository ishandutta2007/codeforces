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
		int sm = 0;
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			sm += a[i];
		}
		bool prime = 1;
		for (int i = 2; i * i <= sm; i++) {
			if (sm % i == 0) {
				prime = 0;
				break;
			}
		}
		if (sm % 2 == 0 || !prime) {
			printf("%d\n", n);
			REP (i, 1, n + 1) {
				printf("%d ", i);
			}
			printf("\n");
		} else {
			int odd = -1;
			REP (i, 1, n + 1) {
				if (a[i] % 2 == 1) odd = i;
			}
			assert(odd != -1);
			printf("%d\n", n - 1);
			REP (i, 1, n + 1) {
				if (i == odd) continue;
				printf("%d ", i);
			}
			printf("\n");
		}
	}
	return 0;
}