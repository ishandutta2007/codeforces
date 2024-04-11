#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
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
#define MAXN 100005

int t;
int n;
char b[MAXN], ans[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", b);
		char prv = '-';
		REP (i, 0, n) {
			if (b[i] + 1 != prv) {
				ans[i] = '1';
				prv = b[i] + 1;
			} else {
				ans[i] = '0';
				prv = b[i];
			}
		}
		REP (i, 0, n) printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}