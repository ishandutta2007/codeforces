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

struct Edge {
	int a, b, cost;
};

bool operator < (Edge a, Edge b) {
	return a.cost < b.cost;
}

const int N = 100005;

int pr[N][20];
int mx[N][20];

int n, m, q;

Edge ed[2 * N];

int p[N];

int gp(int x) {
	if (p[x] != x)
		p[x] = gp(p[x]);
	return p[x];
}

vector<PII> e[N];

bool visited[N];

int in[N], out[N];

bool ancestor(int a, int b) {
	return in[a] <= in[b] && in[b] <= out[a];
}

int tim;

void dfs(int x) {
	in[x] = ++tim;
	visited[x] = true;
	for (int i = 1; i < 20; ++i) {
		pr[x][i] = pr[pr[x][i - 1]][i - 1];
		mx[x][i] = max(mx[x][i - 1], mx[pr[x][i - 1]][i - 1]);
	}
	FORE (it, e[x]) {
		if (!visited[it->ST]) {
			pr[it->ST][0] = x;
			mx[it->ST][0] = it->ND;
			dfs(it->ST);
		}
	}
	out[x] = ++tim;
}

int firstAncestor(int a, int b) {
	int x = 0;
	while (!ancestor(a, b)) {
		int j = 0;
		while (pr[a][j] && !ancestor(pr[a][j], b))
			++j;
		if (j > 0)
			--j;
		x = max(x, mx[a][j]);
		a = pr[a][j];
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		cin >> ed[i].a >> ed[i].b >> ed[i].cost;

	sort(ed + 1, ed + m + 1);

	FOR (i, 1, n)
		p[i] = i;

	LL res = 0;

	int cnt = n;

	for (int i = 1; i <= m; ++i) {
		if (gp(ed[i].a) != gp(ed[i].b)) {
			--cnt;
			res += ed[i].cost;
			e[ed[i].a].PB(MP(ed[i].b, ed[i].cost));
			e[ed[i].b].PB(MP(ed[i].a, ed[i].cost));
			p[gp(ed[i].a)] = gp(ed[i].b);
		}
	}

	dfs(1);

	cin >> q;

	for (int i = 1; i <= q; ++i) {
		int a, b;
		cin >> a >> b;
		if (cnt > 2) {
			printf("-1\n");
		} else if (cnt > 1) {
			if (gp(a) != gp(b))
				cout << res << "\n";
			else
				cout << "-1\n";
		} else {
			cout << res - max(firstAncestor(a, b), firstAncestor(b, a)) << "\n";

		}
	}



	return 0;
}