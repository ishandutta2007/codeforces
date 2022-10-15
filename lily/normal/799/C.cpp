/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
#define fir first
#define sec second
#define MAXN 100319

int n, c, d, ans = 0;
vector <pii> C, D;
char op[5];

#define S 131072
#define INF 0x3f3f3f3f
int t[S << 1];

inline void update(int x, int v) {for (t[x += S + 1] = v; x >>= 1; t[x] = max(t[x << 1], t[(x << 1) ^ 1]));}
inline int query(int l, int r) {
	int ret = -INF; l++, r++;
	for (l += S - 1, r += S + 1; r - l > 1; l >>= 1, r >>= 1) {
		if (~l & 1) ret = max(ret, t[l ^ 1]); 
		if ( r & 1) ret = max(ret, t[r ^ 1]);
	}
	return ret;
}

void solve(vector <pii> &a, int li) {
	if (a.size() < 2) return;
	for (int i = 0; i < 2 * S; i++) t[i] = -INF;
	for (int i = 0; i < a.size(); i++) {
		t[i + 1 + S] = a[i].sec;
	}
	for (int i = S - 1; i; i--) t[i] = max(t[i << 1], t[(i << 1) ^ 1]);
	for (int i = 0, j = a.size() - 1; i < j; i++) {
		while (j > i && a[i].fir + a[j].fir > li) j--; 
		if (j <= i) break;
		update(i, -INF);
		int ret = query(0, j);
		ans = max(ans, query(0, j) + a[i].sec);
		update(i, a[i].sec);
	}
}

void solve2() {
	if (C.size() && D.size()) {
		int a = -INF, b = -INF;
		for (int i = 0; i < C.size() && C[i].fir <= c; i++) a = max(a, C[i].sec);
		for (int i = 0; i < D.size() && D[i].fir <= d; i++) b = max(b, D[i].sec);
		ans = max(ans, a + b);
	}
}

int main() {
	cin >> n >> c >> d;
	for (int i = 1, b, p; i <= n; i++) {
		scanf("%d%d%s", &b, &p, op);
		if (op[0] == 'C') C.push_back(make_pair(p, b));
		else D.push_back(make_pair(p, b));
	}
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());
	solve(C, c); solve(D, d);
	solve2();
	printf("%d\n", ans);
	return 0;
}