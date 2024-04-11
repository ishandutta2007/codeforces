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

int n;
int a[MAXN];
ii p[MAXN];
int l[MAXN], r[MAXN];
stack<ii> stk;
int ans[MAXN];

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		p[i] = MP(a[i], i);
	}
	REP (i, 0, n) {
		while (!stk.empty() && stk.top().FI >= a[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			l[i] = 0;
		} else {
			l[i] = stk.top().SE + 1;
		}
		stk.push(MP(a[i], i));
	}
	while (!stk.empty()) stk.pop();
	RREP (i, n - 1, 0) {
		while (!stk.empty() && stk.top().FI >= a[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			r[i] = n - 1;
		} else {
			r[i] = stk.top().SE - 1;
		}
		stk.push(MP(a[i], i));
	}
	sort(p, p + n, greater<ii>());
	int cnt = 0;
	REP (i, 0, n) {
		int pos = p[i].SE;
		int nw = r[pos] - l[pos];
		while (cnt <= nw) {
			ans[cnt++] = p[i].FI;
		}
	}
	REP (i, 0, n) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}