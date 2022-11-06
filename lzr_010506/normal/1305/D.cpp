#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 1010;
int n;
set<int> G[N], t;

void Erase(int u, int v)
{
    t.erase(u);
	t.erase(v);
	int V = *G[v].begin();
	G[v].erase(V);
	G[V].erase(v);
	int U = *G[u].begin();
	G[u].erase(U);
	G[U].erase(u);
}

int main()
{
	n = read();
	rep(i, 1, n) t.insert(i);
	rep0(i, n - 1)
	{
		int u = read();
		int v = read();
		G[u].insert(v);
		G[v].insert(u);
	}

	int R = n;
	while (R > 1)
	{
		int u = -1, v = -1;
		rep(i, 1, n)
			if (G[i].size() ==1)
			{
				if(u == -1) u = i;
				else {v = i; break;}
			}
		Erase(u, v);
		printf("? %d %d\n", u, v);
		fflush(stdout);
		int lca = read();
		if (lca == u)
		{
			printf("! %d\n",u);
			fflush(stdout);
			return 0;
		}
		if (lca == v)
		{
			printf("! %d\n", v);
			fflush(stdout);
			return 0;
		}
		R --;
		R --;
	}
	if (R == 1)
	{
		printf("! %d\n",*t.begin());
		fflush(stdout);
		return 0;
	}
}