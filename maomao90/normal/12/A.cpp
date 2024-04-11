#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
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
#define MAXN 200005

char grid[3][3];

int main() {
	REP (i, 0, 3) scanf(" %s", &grid[i]);
	REP (i, 0, 3) {
		REP (j, 0, 3) {
			if (grid[i][j] != grid[2 - i][2 - j]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}