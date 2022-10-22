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
typedef vector<ll> vll;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
int u[MAXN], s[MAXN];
set<int> used;
vll uni[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		used.clear();
		REP (i, 1, n + 1) uni[i].clear();
		REP (i, 0, n) {
			scanf("%d", &u[i]);
		}
		REP (i, 0, n) {
			scanf("%d", &s[i]);
		}
		REP (i, 0, n) {
			uni[u[i]].pb(s[i]);
			used.insert(u[i]);
		}
		for (int j : used) {
			sort(ALL(uni[j]), greater<ll>());
		}
		for (int j : used) {
			REP (k, 1, uni[j].size()) {
				uni[j][k] += uni[j][k - 1];
			}
		}
		REP (i, 1, n + 1) {
			ll ans = 0;
			for (auto j = used.begin(); j != used.end();) {
				int sze = uni[*j].size();
				int rem = sze % i;
				ll cur = 0;
				if (sze - rem - 1 >= 0) cur += uni[*j][sze - rem - 1];
				auto temp = j++;
				if (cur == 0) {
					used.erase(*temp);
				}
				ans += cur;
			}
			printf("%lld ", ans);
		}
		printf("\n");
	}
	return 0;
}