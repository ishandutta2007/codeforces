// time-limit: 2000
// problem-url: https://codeforces.com/contest/1622/problem/B

// Dear friends, since God so loved us, we also ought to love one another
// 1 John 4:11
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
int p[MAXN];
char s[MAXN];
vi on, ze;
int ans[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &p[i]);
		}
		on.clear();
		ze.clear();
		scanf(" %s", s);
		REP (i, 0, n) {
			if (s[i] == '1') {
				on.pb(i);
			} else {
				ze.pb(i);
			}
		}
		auto f = [&] (int l, int r) {
			return p[l] < p[r];
		};
		sort(ALL(on), f);
		sort(ALL(ze), f);
		REP (i, 0, ze.size()) {
			ans[ze[i]] = i + 1;
		}
		REP (i, 0, on.size()) {
			ans[on[i]] = i + ze.size() + 1;
		}
		REP (i, 0, n) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}