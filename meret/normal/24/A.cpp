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

const int N = 105;

int cost[N][N];
bool vis[N];

int sum, sum2;

int n;

void dfs(int x) {
	vis[x] = true;
	if (cost[x][1] && vis[1] && vis[2] && vis[3])
		sum2 += cost[x][1];
	for (int i = 1; i <= n; ++i) {
		if ((cost[x][i] || cost[i][x]) && !vis[i]) {
			sum2 += cost[x][i];
			dfs(i);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, b,c;
		scanf("%d %d %d", &a, &b, &c);
		cost[b][a] = c;
		sum += c;
	}
	dfs(1);
	printf("%d\n", min(sum2, sum - sum2));
}