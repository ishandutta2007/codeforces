#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n, m;
char s[MAXN], t[MAXN];
int mn[MAXN], mx[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	scanf(" %s", &s);
	scanf(" %s", &t);
	int ptr = 0;
	REP (i, 0, m) {
		while (ptr < n && s[ptr] != t[i]) {
			ptr++;
		}
		mn[i] = ptr++;
	}
	ptr = n - 1;
	RREP (i, m - 1, 0) {
		while (ptr >= 0 && s[ptr] != t[i]) {
			ptr--;
		}
		mx[i] = ptr--;
	}
	int ans = 0;
	REP (i, 1, m) {
		mxto(ans, mx[i] - mn[i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}