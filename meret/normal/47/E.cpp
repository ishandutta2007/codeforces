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

LD g = 9.8;

LD cosa, sina;

LD atX(LD x) {
	LD t = x / cosa;
	return sina * t - g * t * t / 2;
}

LD land() {
	return 2 * sina * cosa / g;
}

int n, m;
int V;

pair<LD, LD> ans[10005];
pair<LD, int> query[10005];

pair<LD, LD> walls[100005];

int main()
{
	scanf("%d %d", &n, &V);

	for (int i = 1; i <= n; ++i) {
		scanf("%Lf", &query[i].ST);
		query[i].ND = i;
	}

	sort(query + 1, query + n + 1);

	scanf("%d", &m);

	for (int i = 1; i <= m; ++i) {
		scanf("%Lf %Lf", &walls[i].ST, &walls[i].ND);
	}

	sort(walls + 1, walls + m + 1);

	int z = 0;

	for (int i = 1; i <= m; ++i) {
		if (z == 0 || walls[z].ST < walls[i].ST - 1e-9)
			++z;
		walls[z] = walls[i];
	}
	
	m = z;

	int c = 1;

	for (int i = 1; i <= n; ++i) {
		cosa = cosl(query[i].ST) * V;
		sina = sinl(query[i].ST) * V;
		LD ld = land();
		while (c <= m && walls[c].ST < ld - 1e-9 && atX(walls[c].ST) > walls[c].ND + 1e-12)
			++c;
		if (c <= m && walls[c].ST < ld - 1e-9 && atX(walls[c].ST) < walls[c].ND + 1e-12)
			ans[query[i].ND] = MP(walls[c].ST, atX(walls[c].ST));
		else
			ans[query[i].ND] = MP(ld, 0.0l);
	}

	for (int i = 1; i <= n; ++i)
		printf("%.9Lf %.9Lf\n", ans[i].ST, ans[i].ND);

    return 0;
}