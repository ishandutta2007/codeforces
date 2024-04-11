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

int solve(char c) {
	int l = 0, r = n - 1;
	int res = 0;
	while (l < r) {
		while (s[l] != s[r] && l < r) {
			if (s[l] == c) {
				l++;
				res++;
			} else if (s[r] == c) {
				r--;
				res++;
			} else {
				break;
			}
		}
		if (s[l] != s[r]) {
			return INF;
		}
		l++;
		r--;
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		int l = 0, r = n - 1;
		while (s[l] == s[r] && l < r) {
			l++;
			r--;
		}
		if (l >= r) {
			printf("0\n");
			continue;
		}
		int ans = min(solve(s[l]), solve(s[r]));
		if (ans == INF) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}