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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int t;
int n;
int a[MAXN + 5], sa[MAXN + 5];
int cnt[MAXN + 5][2];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			sa[i] = a[i];
			cnt[a[i]][i % 2]++;
		}
		sort(sa + 1, sa + n + 1);
		REP (i, 1, n + 1) {
			cnt[sa[i]][i % 2]--;
		}
		bool pos = 1;
		REP (i, 0, MAXN) {
			REP (j, 0, 2) {
				if (cnt[i][j] != 0) {
					pos = 0;
				}
			}
		}
		if (pos) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}

/*
1
6
2 1 2 1 2 1
*/