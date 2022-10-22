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
#define MAXN 300005

int t;
int n, k, l;
int d[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &k, &l);
		bool isPos = true;
		REP (i, 1, n + 1) {
			scanf("%d", &d[i]);
		}
		int curt = k, inc = -1;
		REP (i, 1, n + 1) {
			curt += inc;
			if (d[i] + k <= l) {
				inc = -1;
				curt = k;
				continue;
			}
			if (inc == -1) {
				curt = min(curt, l - d[i]);
			} 
			if (curt < 0 || d[i] + curt > l) {
				isPos = false;
				break;
			}
			if (curt == 0) inc = 1;
		}
		if (isPos) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}