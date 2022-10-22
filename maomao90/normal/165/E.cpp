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
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 1000005
#define MAXL 22
#define MAXA 5000005

int n;
int a[MAXN];
int f[MAXA];

int main() {
	scanf("%d", &n);
	memset(f, -1, sizeof f);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		f[a[i]] = a[i];
	}
	REP (i, 0, MAXL) {
		REP (j, 0, (1 << MAXL)) {
			if (j & (1 << i) && f[j] == -1) f[j] = f[j ^ (1 << i)];
		}
	}
	REP (i, 0, n) {
		int inv = ((1 << MAXL) - 1) & (~a[i]);
		printf("%d ", f[inv]);
	}
	printf("\n");
	return 0;
}