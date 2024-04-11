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

int t;
int n, m, x;
ii h[MAXN], blk[MAXN];
int ans[MAXN], mp[MAXN];
priority_queue<ii, vii, greater<ii>> pq;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &x);
		REP (i, 0, n) {
			scanf("%d", &h[i].FI);
			h[i].SE = i;
		}
		sort(h, h + n, greater<ii>());
		while (!pq.empty()) pq.pop();
		REP (i, 0, m) {
			blk[i] = MP(0, i);
			pq.push(MP(0, i));
		}
		REP (i, 0, n) {
			auto [w, u] = pq.top(); pq.pop();
			blk[u].FI = w + h[i].FI;
			pq.push(MP(blk[u].FI, u));
			ans[h[i].SE] = u;
		}
		bool pos = 1;
		sort(blk, blk + m);
		REP (i, 1, m) {
			if (abs(blk[i].FI - blk[i - 1].FI) > x) {
				pos = 0;
			}
		}
		REP (i, 0, m) {
			mp[blk[i].SE] = i;
		}
		if (pos) {
			printf("YES\n");
			REP (i, 0, n) {
				printf("%d ", mp[ans[i]] + 1);
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}