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
#define MAXL 31

int t;
int n;
int a[MAXN];
int cnt[MAXL + 5];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		REP (i, 0, MAXL + 5) {
			cnt[i] = 0;
		}
		REP (i, 0, n) {
			REP (j, 0, MAXL) {
				if (a[i] & (1 << j)) {
					cnt[j]++;
				}
			}
		}
		REP (i, 1, n + 1) {
			bool pos = 1;
			REP (j, 0, MAXL) {
				if (cnt[j] % i != 0) {
					pos = 0;
				}
			}
			if (pos) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}