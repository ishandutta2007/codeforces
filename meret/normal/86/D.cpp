#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int n, queries;

int a[200005];

const int s = 400;

bool cmp(pair<PII, int> a, pair<PII, int> b) {
	if (a.ST.ST / s != b.ST.ST / s)
		return a.ST.ST / s < b.ST.ST / s;
	return a.ST.ND < b.ST.ND;
}

pair<PII, int> q[200005];

LL answer[200005];

int got[1000005];

int main() {
	scanf("%d %d", &n, &queries);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= queries; ++i) {
		scanf("%d %d", &q[i].ST.ST, &q[i].ST.ND);
		q[i].ND = i;
		answer[i] = -1;
	}
	sort(q + 1, q + queries + 1, cmp);
	LL cur = 0;
	int cl = 1;
	int cr = 0;
	for (int i = 1; i <= queries; ++i) {
		while (cr < q[i].ST.ND) {
			++cr;
			cur += a[cr] * LL(2 * got[a[cr]] + 1);
			++got[a[cr]];
		}
		while (cr > q[i].ST.ND) {
			--got[a[cr]];
			cur -= a[cr] * LL(2 * got[a[cr]] + 1);
			--cr;
		}
		while (cl < q[i].ST.ST) {
			--got[a[cl]];
			cur -= a[cl] * LL(2 * got[a[cl]] + 1);
			++cl;
		}
		while (cl > q[i].ST.ST) {
			--cl;
			cur += a[cl] * LL(2 * got[a[cl]] + 1);
			++got[a[cl]];
		}
		answer[q[i].ND] = cur;
	}
	for (int i = 1; i <= queries; ++i)
		cout << answer[i] << "\n";
}