//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT

int n, m;
bool e[105][105];

int t[2005];
int ans[2005];

int edges;

int resDfs;

bool v[105];

void dfs(int x) {
	v[x] = true;
	for (int i = 1; i <= n; ++i)
		if (e[x][i]) {
			++resDfs;
			if (!v[i])
				dfs(i);
		}
}

bool connected(int x) {
	CLR(v, 0);
	resDfs = 0;
	dfs(x);
	return resDfs == 2 * edges;
}

void addEdge(int a, int b) {
	++edges;
	e[a][b] = true;
	e[b][a] = true;
}

void remEdge(int a, int b) {
	--edges;
	e[a][b] = false;
	e[b][a] = false;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m + 1; ++i) {
		scanf("%d", &t[i]);
	}

	edges = 0;

	int last;

	for (last = m; last >= 1; --last) {
		addEdge(t[last], t[last + 1]);
		bool got = false;
		for (int j = t[last + 1] + 1; j <= n; ++j)
			if (e[t[last]][j]) {
				remEdge(t[last], j);
				if (connected(j)) {
					t[last + 1] = j;
					got = true;
					break;
				}
				addEdge(t[last], j);
			}
		if (got)
			break;
	}

	if (last == 0) {
		printf("No solution\n");
		return 0;
	}

	++last;

	for (; last <= m; ++last) {
		for (int j = 1; j <= n; ++j)
			if (e[t[last]][j]) {
				remEdge(t[last], j);
				if (connected(j)) {
					t[last + 1] = j;
					break;
				}
				addEdge(t[last], j);
			}
	}

	for (int i = 1; i <= m; ++i)
		printf("%d ", t[i]);
	printf("%d\n", t[m + 1]);

	return 0;
}