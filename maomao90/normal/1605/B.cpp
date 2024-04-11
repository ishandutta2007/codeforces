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
char s[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		bool done = 1;
		REP (i, 1, n) {
			if (s[i] < s[i - 1]) {
				done = 0;
				break;
			}
		}
		if (done) {
			printf("0\n");
			continue;
		}
		int l = 0, r = n - 1;
		vi ans;
		while (1) {
			while (s[l] != '1' && l < n) {
				l++;
			}
			while (s[r] != '0' && r >= 0) {
				r--;
			}
			if (l >= n || r < 0) break;
			if (l > r) break;
			ans.pb(l);
			ans.pb(r);
			l++; r--;
		}
		sort(ALL(ans));
		printf("1\n");
		printf("%d", (int) ans.size());
		for (int i : ans) {
			printf(" %d", i + 1);
		}
		printf("\n");
	}
	return 0;
}