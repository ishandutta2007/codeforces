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
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 100005;

double sumPath[N];
double sumP[N];

double pEnter[N], pExit[N];

vector<int> e[N];

bool vis[N];

int subSz[N];

void dfs1(int x) {
	vis[x] = true;
	sumPath[x] = 0;
	sumP[x] = pEnter[x];
	subSz[x] = 1;
	FORE (it, e[x]) {
		if (!vis[*it]) {
			dfs1(*it);
			sumPath[x] += sumPath[*it] + sumP[*it];
			sumP[x] += sumP[*it];
			subSz[x] += subSz[*it];
		}
	}
}

double result;

int n;

void dfs2(int x, double sumAbove = 0, double sumPAbove = 0, int par = -1) {
	vis[x] = true;
	if (par != -1) {
		result += pExit[x] * (sumPAbove * (n - subSz[x]));
		result += pExit[par] * (sumP[x] * (subSz[x]));
	}
	FORE (it, e[x]) {
		if (!vis[*it]) {
			dfs2(*it, sumAbove + sumPAbove + sumP[x] - 2 * sumP[*it] + sumPath[x] - sumPath[*it], sumPAbove + sumP[x] - sumP[*it], x);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].PB(b);
		e[b].PB(a);
	}
	double sumEnter = 0, sumExit = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lf %lf", &pEnter[i], &pExit[i]);
		sumEnter += pEnter[i];
		sumExit += pExit[i];
	}
	for (int i = 1; i <= n; ++i) {
		pEnter[i] /= sumEnter;
		pExit[i] /= sumExit;
	}
	ZERO(vis);
	dfs1(1);
	ZERO(vis);
	dfs2(1);
	printf("%.10lf\n", result);
}