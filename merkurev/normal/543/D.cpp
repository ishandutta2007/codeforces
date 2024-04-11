#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int mod = (int) 1e9 + 7;

int sum(int a, int b)
{
	int ans = a + b;
	if (ans >= mod)
		ans -= mod;
	return ans;
}
void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}


const int maxn = (int) 2e5 + 100;
vector <int> ch[maxn];
int p[maxn];

int dp[maxn][2];
int udp[maxn][2];

void getNxt(int p0, int p1, int c0, int c1, int &n0, int &n1)
{
	n0 = mul(p0, c0);
	n1 = mul(p1, c1);
	add(n1, mul(p1, c0) );
	add(n1, mul(p0, c1) );
}

void dfs(int v)
{
	dp[v][0] = 1;
	for (int nv : ch[v] )
	{
		dfs(nv);
		getNxt(dp[v][0], dp[v][1], udp[nv][0], udp[nv][1], dp[v][0], dp[v][1] );
	}
	udp[v][0] = dp[v][0];
	udp[v][1] = dp[v][1];
	add(udp[v][1], udp[v][0] );
}

int ans[maxn];
vector <int> to0[maxn], to1[maxn];

void getAns(int v, int up0 = 1, int up1 = 0)
{
	ans[v] = mul(sum(dp[v][0], dp[v][1] ), sum(up0, up1) );

	int n = (int) ch[v].size();
	to0[v].resize(n + 1);
	to1[v].resize(n + 1);
	to0[v].back() = 1;
	to1[v].back() = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int nc = ch[v][i];
		getNxt(to0[v][i + 1], to1[v][i + 1], udp[nc][0], udp[nc][1], to0[v][i], to1[v][i] );
	}


	for (int i = 0; i < n; i++)
	{
		int nc = ch[v][i];
		int nup0, nup1;
		getNxt(up0, up1, to0[v][i + 1], to1[v][i + 1], nup0, nup1);
		add(nup1, nup0);

		getAns(nc, nup0, nup1);
		getNxt(up0, up1, udp[nc][0], udp[nc][1], up0, up1);
	}
}


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &p[i] );
		p[i]--;
		ch[p[i] ].push_back(i);
	}
	dfs(0);
	getAns(0);	

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] );


	return 0;
}