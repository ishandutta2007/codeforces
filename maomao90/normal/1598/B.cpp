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
#define MAXN 1005

int t;
int n;
int a[MAXN][5];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			REP (j, 0, 5) {
				scanf("%d", &a[i][j]);
			}
		}
		bool ans = 0;
		REP (i, 0, 5) {
			REP (j, i + 1, 5) {
				bool pos = 1;
				int sm[2] = {0, 0};
				REP (k, 0, n) {
					sm[0] += a[k][i];
					sm[1] += a[k][j];
					if (a[k][i] == 0 && a[k][j] == 0) {
						pos = 0;
						break;
					}
				}
				REP (k, 0, 2) {
					if (sm[k] < n / 2) {
						pos = 0;
						break;
					}
				}
				if (pos) {
					ans = 1;
					break;
				}
			}
			if (ans) {
				break;
			}
		}
		if (ans) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}