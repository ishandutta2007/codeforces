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
typedef pair<int,int> PII;
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

const int N = 10005;

int n, m;

vector<PII> e[N];
bool visited[N];

int pEdge[N];
int p[N];

int h[N];

int low[N];

PII edges[N];

vector<int> badEdges;

int inTime[N], outTime[N];
int curTime;

void dfs(int x) {
	inTime[x] = ++curTime;
	visited[x] = true;
	low[x] = h[x];
	for (vector<PII>::iterator c = e[x].begin(); c != e[x].end(); ++c) {
		if (!visited[c->ST]) {
			h[c->ST] = h[x] + 1;
			p[c->ST] = x;
			pEdge[c->ST] = c->ND;
			dfs(c->ST);
			low[x] = min(low[x], low[c->ST]);
		} else if (h[c->ST] < h[x]) {
			if (h[x] % 2 == h[c->ST] % 2)
				badEdges.PB(c->ND);
			else if (c->ST != p[x])
				low[x] = min(low[x], h[c->ST]);
		}
	}
	outTime[x] = ++curTime;
}

bool ancestor(int a, int b) {
	return inTime[a] <= inTime[b] && inTime[b] <= outTime[a];
}

bool goodEdge(int a, int b) {
	return low[a] > h[b];
}

vector<int> edgesOnPath(int low, int high) {
	vector<int> result;
	while (low != high) {
		if (goodEdge(low, p[low]))
			result.PB(pEdge[low]);
		low = p[low];
	}
	return result;
}

int lca(int a, int b) {
	if (h[a] < h[b])
		swap(a, b);
	while (!ancestor(b, a))
		b = p[b];
	return b;
}

int lowPoint(int a, int b) {
	if (h[a] < h[b])
		swap(a, b);
	if (!ancestor(b, a))
		return -1;
	else
		return a;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges[i] = MP(a, b);
		e[a].PB(MP(b, i));
		e[b].PB(MP(a, i));
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			int prevBadEdges = badEdges.size();
			dfs(i);
			if (prevBadEdges > 0 && prevBadEdges < badEdges.size()) {
				printf("0\n");
				return 0;
			}
		}
	}
	vector<int> result;
	if (badEdges.size() == 0) {
		for (int i = 1; i <= m; ++i)
			result.PB(i);
	} else if (badEdges.size() == 1) {
		int a = edges[badEdges[0]].ST,
				b = edges[badEdges[0]].ND;
		if (h[a] < h[b])
			swap(a, b);
		result = edgesOnPath(a, b);
		result.PB(badEdges[0]);
		sort(ALL(result));
	} else {
		int low = edges[badEdges[0]].ST, high = edges[badEdges[0]].ND;
		if (h[low] < h[high])
			swap(low, high);
		for (int i = 1; i < badEdges.size(); ++i) {
			int a = edges[badEdges[i]].ST, b = edges[badEdges[i]].ND;
			if (h[a] < h[b])
				swap(a, b);
			low = lca(low, a);
			high = lowPoint(high, b);
			if (high == -1 || !ancestor(high, low))
				break;
		}
		if (high != -1 && ancestor(high, low))
			result = edgesOnPath(low, high);
		sort(ALL(result));
	}
	printf("%u\n", result.size());
	for (int i = 0; i + 1 < result.size(); ++i)
		printf("%d ", result[i]);
	if (!result.empty())
		printf("%d\n", result[result.size() - 1]);
}