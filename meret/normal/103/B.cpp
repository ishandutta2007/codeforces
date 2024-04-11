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

int n, m;

int p[105];

int gp(int x) {
	if (p[x] != x)
		p[x] = gp(p[x]);
	return p[x];
}

int main() {
	scanf("%d %d", &n, &m);
	if (n != m) {
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		p[gp(a)] = gp(b);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (p[i] == i)
			++cnt;
	if (cnt == 1)
		printf("FHTAGN!\n");
	else
		printf("NO\n");
}