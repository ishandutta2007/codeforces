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

const int N = 2005;

bool e[N][N];

bool et[N][N];

int s[N], ss;

int cv[N], sv;

int comp[N];

int cc;

int h[N];
int p[N];

int n;

int dfs(int x) {
	s[ss++] = x;
	cv[sv++] = x;
	h[x] = h[p[x]] + 1;
	int ret = h[x];
	for (int i = 1; i <= n; ++i) {
		if (e[x][i] && !p[i]) {
			p[i] = x;
			int a = dfs(i);
			ret = min(ret, a);
			if (a > h[x]) {
				while (s[ss] != i) {
					comp[s[ss - 1]] = cc + 1;
					--ss;
				}
				++cc;
			}
		} else if (e[x][i] && i != p[x])
			ret = min(ret, h[i]);
	}
	if (p[x] == -1) {
		while (ss) {
			comp[s[ss - 1]] = cc + 1;
			--ss;
		}
		++cc;
	}
	return ret;
}

int subtr[N];
int sons[N];
int dp[N];
bool vis[N];

vector<int> ed[N];


void dfs2(int x, bool first = true) {
	vis[x] = true;
	subtr[x] = 1;
	dp[x] = 0;
	sons[x] = 0;
	int best1 = 0;
	int best2 = 0;
	FORE (it, ed[x]) {
		int i = *it;
		if (et[x][i] && !vis[i]) {
			dfs2(i, false);
			subtr[x] += subtr[i];
			int cr = min(subtr[i] - 1, sons[i] + 1);
			sons[x] += cr;
			dp[x] += cr;;
			cr -= dp[i];
			if (cr > best1) {
				best2 = best1;
				best1 = cr;
			} else if (cr > best2)
				best2 = cr;
		}
	}
	dp[x] -= best1;
	if (first)
		dp[x] -= best2;
}

int m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = true;
	}

	int res = 0;

	for (int k = 1; k <= n; ++k) {
		if (!p[k]) {
			if (k > 1)
				++res;
			p[k] = -1;
			cc = 0;
			sv = 0;
			dfs(k);
			for (int i = 1; i <= cc; ++i)
				for (int j = 1; j <= cc; ++j)
					et[i][j] = et[j][i] = false;

			res += sv - cc;

			for (int i = 0; i < sv; ++i) {
				for (int j = 0; j < sv; ++j) {
					if (comp[cv[i]] != comp[cv[j]] && e[cv[i]][cv[j]])
						et[comp[cv[i]]][comp[cv[j]]] = true;
				}
			}

			for (int i = 1; i <= cc; ++i)
				for (int j = 1; j <= cc; ++j)
						if (et[i][j])
							ed[i].PB(j);
			int cur = n;

			for (int i = 1; i <= cc; ++i) {
				for (int j = 1; j <= cc; ++j)
					vis[j] = false;
				dfs2(i);
				cur = min(cur, dp[i]);
			}

			for (int i = 1; i <= cc; ++i)
				ed[i].clear();

			res += cur;
		}
	}
	
	printf("%d\n", res);

	return 0;
}