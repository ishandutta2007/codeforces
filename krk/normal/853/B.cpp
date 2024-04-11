#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const ll Inf = 10000000000000ll;

struct pos {
	int d, c, wh;
	pos(int d = 0, int c = 0, int wh = 0): d(d), c(c), wh(wh) {}
	bool operator <(const pos &u) const {
		if (d != u.d) return d < u.d;
		if (c != u.c) return c < u.c;
		return wh < u.wh;
	}
};

int n, m, k;
vector <pos> inc, outg;
ll my[Maxn];
ll tot, costinc[Maxn], costoutg[Maxn];
ll res = Inf;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int d, f, t, c; scanf("%d %d %d %d", &d, &f, &t, &c);
		if (f == 0) outg.push_back(pos(d, c, t));
		else inc.push_back(pos(d, c, f));
	}
	sort(outg.rbegin(), outg.rend());
	fill(my, my + n + 1, Inf); tot = Inf * ll(n);
	int pnt = 0;
	for (int i = Maxn - 1; i >= 0; i--) {
		while (pnt < outg.size() && outg[pnt].d >= i) {
			tot -= my[outg[pnt].wh];
			my[outg[pnt].wh] = min(my[outg[pnt].wh], ll(outg[pnt].c));
			tot += my[outg[pnt].wh];
			pnt++;
		}
		costoutg[i] = tot;
	}
	sort(inc.begin(), inc.end());
	fill(my, my + n + 1, Inf); tot = Inf * ll(n);
	pnt = 0;
	for (int i = 0; i < Maxn; i++) {
		while (pnt < inc.size() && inc[pnt].d <= i) {
			tot -= my[inc[pnt].wh];
			my[inc[pnt].wh] = min(my[inc[pnt].wh], ll(inc[pnt].c));
			tot += my[inc[pnt].wh];
			pnt++;
		}
		costinc[i] = tot;
	}
	for (int i = 0; i + k + 1 < Maxn; i++)
		res = min(res, costinc[i] + costoutg[i + k + 1]);
	printf("%I64d\n", res < Inf? res: -1ll);
	return 0;
}