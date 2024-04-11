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
#define All(x) (x).begin(), (x).end()
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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
char G[N][N];
int r[N * N], v[N][N];
int n, m, id, ans;

void dfs(int x, int y)
{
	v[x][y] = id;
	rep0(i, 4)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		//printf("%d %d %d %d\n", x, y, nx, ny);
		if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
		if(v[nx][ny]) continue;
		if(G[nx][ny] == '*') ans ++;
		else dfs(nx, ny);
	}
}

int main()
{
	n = read();
	m = read();
	int k = read();
	rep(i, 1, n) scanf("%s", G[i] + 1);
	//cout << k << endl;
	rep(i, 1, n)
		rep(j, 1, m)
			if(G[i][j] == '.' && !v[i][j])
			{
				ans = 0;
				id ++;
				dfs(i, j);
				//printf("%d\n", ans);
				r[id] = ans;
			}
	while(k --)
	{
		int x, y;
		x = read();
		y = read();
		printf("%d\n", r[v[x][y]]);
	}

	return 0;
}