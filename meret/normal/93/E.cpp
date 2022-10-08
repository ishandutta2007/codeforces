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

int p[105];
int cp;

LL mx = 10000000000000LL;

LL res = 0;

LL dp[105][20005];
bool vis[105][20005];

LL go(int x, LL cr, int used) {
	if (cr == 0)
		return 0;
	if (cr <= 20000 && vis[x][cr]) {
		return (used ? -dp[x][cr] : dp[x][cr]);
	}
	LL cur = 0;
	if (x == cp) {
		cur = (used ? -cr : cr);
	} else {
		cur += go(x + 1, cr / p[x], used ^ 1);
		cur += go(x + 1, cr, used);
	}
	if (cr <= 20000) {
		vis[x][cr] = true;
		dp[x][cr] = (used ? -cur : cur);
	}
	return cur;
}

int main() {
	cin >> mx >> cp;
	for (int i = 0; i < cp; ++i)
		cin >> p[i];
	sort(p, p + cp);
	reverse(p, p + cp);
	res = go(0, mx, 0);
	cout << res << endl;
}