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

vector<PII> e[1005];
int n, m;

const int INF = 1000000001;

void dijkstra(int start, int* dist) {
	for (int i = 1; i <= n; ++i)
		dist[i] = INF;
	dist[start] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(MP(0, start));
	while (!q.empty()) {
		int c = q.top().second;
		int cd = q.top().first;
		q.pop();
		if (cd > dist[c])
			continue;
		FOREACH (it, e[c]) {
			int nd = cd + it->second;
			if (nd < dist[it->first]) {
				dist[it->first] = nd;
				q.push(MP(nd, it->first));
			}
		}
	}
}

int dist[1005][1005];

LL d2[1005];

int maxDist[1005], cost[1005];

const LL LINF = 1000000000000000000LL;

int main() {
	scanf("%d %d", &n, &m);
	int start, final;
	scanf("%d %d", &start, &final);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a].PB(MP(b, c));
		e[b].PB(MP(a, c));
	}

	for (int i = 1; i <= n; ++i)
		dijkstra(i, dist[i]);

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &maxDist[i], &cost[i]);
	}

	for (int i = 1; i <= n; ++i) {
		d2[i] = LINF;
	}

	priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > q;
	q.push(MP(0LL, start));

	d2[start] = 0;

	while (!q.empty()) {
		int c = q.top().second;
		LL cd = q.top().first;
		q.pop();
		if (cd > d2[c])
			continue;
		for (int i = 1; i <= n; ++i) {
			if (dist[c][i] <= maxDist[c]) {
				LL nd = d2[c] + cost[c];
				if (nd < d2[i]) {
					d2[i] = nd;
					q.push(MP(nd, i));
				}
			}
		}
	}

	if (d2[final] == LINF)
		printf("-1\n");
	else {
		cout << d2[final] << endl;
	}
}