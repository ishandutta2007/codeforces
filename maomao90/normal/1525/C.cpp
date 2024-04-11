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
#define MAXN 300005

int t;
int n, m;
int x[MAXN];
vii v[2];
int dir[MAXN];
int ans[MAXN];

bool done[MAXN];
void solve(int id) {
	REP (i, 0, n) done[i] = 0;
	stack<int> stk;
	RREP (i, v[id].size() - 1, 0) {
		if (dir[v[id][i].SE] == -1) {
			stk.push(v[id][i].SE);
		} else {
			if (!stk.empty()) {
				int tmp = stk.top(); stk.pop();
				int diff = x[tmp] - v[id][i].FI;
				ans[v[id][i].SE] = diff / 2;
				ans[tmp] = diff / 2;
				done[tmp] = 1;
				done[v[id][i].SE] = 1;
			}
		}
	}
	while (!stk.empty()) stk.pop();
	RREP (i, v[id].size() - 1, 0) {
		if (done[v[id][i].SE]) continue;
		if (dir[v[id][i].SE] == 1) {
			if (stk.empty()) {
				stk.push(v[id][i].SE);
			} else {
				int tmp = stk.top(); stk.pop();
				int diff = x[tmp] - v[id][i].FI;
				int res = m - x[tmp] + diff / 2;
				ans[v[id][i].SE] = res;
				ans[tmp] = res;
				done[tmp] = 1;
				done[v[id][i].SE] = 1;
			}
		}
	}
	while (!stk.empty()) stk.pop();
	REP (i, 0, v[id].size()) {
		if (done[v[id][i].SE]) continue;
		if (dir[v[id][i].SE] == -1) {
			if (stk.empty()) {
				stk.push(v[id][i].SE);
			} else {
				int tmp = stk.top(); stk.pop();
				int diff = v[id][i].FI - x[tmp];
				int res = x[tmp] + diff / 2;
				ans[v[id][i].SE] = res;
				ans[tmp] = res;
				done[tmp] = 1;
				done[v[id][i].SE] = 1;
			}
		}
	}
	vii rem;
	REP (i, 0, v[id].size()) {
		if (!done[v[id][i].SE]) rem.pb(v[id][i]);
	}
	if (rem.size() == 2) {
		int diff1 = rem[0].FI, diff2 = m - rem[1].FI;
		int res = 0;
		if (diff1 < diff2) {
			res = diff1;
			rem[1].FI += res;
			res += (m - rem[1].FI) + rem[1].FI / 2;
		} else {
			res = diff2;
			rem[0].FI -= res;
			res += rem[0].FI + (m - rem[0].FI) / 2;
		}
		ans[rem[0].SE] = res;
		ans[rem[1].SE] = res;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, 2) v[i].clear();
		REP (i, 0, n) {
			scanf("%d", &x[i]);
			v[x[i] % 2].pb(x[i], i);
		}
		REP (i, 0, 2) {
			sort(ALL(v[i]));
		}
		REP (i, 0, n) {
			char c; scanf(" %c", &c);
			if (c == 'L') dir[i] = -1;
			else dir[i] = 1;
		}
		REP (i, 0, n) {
			ans[i] = -1;
		}
		REP (i, 0, 2) {
			solve(i);
		}
		REP (i, 0, n) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}