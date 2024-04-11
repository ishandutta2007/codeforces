#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
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
ll p, q;
int cnt, tot, fat[400010][22], f[400010][22], last, opt, Q;
namespace Tree
{
	int fa[400010][22], len[400010];
	ll Dep[400010];
	void init(int p, int x)
	{
		Dep[p] = x;
		len[p] = 1;
		rep(i, 0, 20)
			fa[p][i] = p;
	}
	void add(int fat, int p, int x)
	{
		fa[p][0] = fat;
		len[p] = len[fat] + 1;
		Dep[p] = Dep[fat] + x;
		rep(i, 1, 20)
			fa[p][i] = fa[fa[p][i - 1]][i - 1];
	}
	int query(int p, ll X)
	{
		if(Dep[p] <= X)	return len[p];
		int x = p;
		rrep(i, 20, 0)
			if(Dep[p] - Dep[fa[x][i]] <= X)
				x = fa[x][i];
		return len[p] - len[x];
	}
};
using namespace Tree;
void add(int p,int W)
{
	int u = ++ cnt;
	fat[u][0] = p;
	f[u][0] = W;
	rep(i, 1, 20)
	{
		fat[u][i] = fat[fat[u][i - 1]][i - 1];
		f[u][i] = max(f[u][i - 1], f[fat[u][i - 1]][i - 1]);
	}
	int x = p;
	rrep(i, 20, 0)
		if(f[x][i] < W)
			x = fat[x][i];
	if(x == 1 && W) init(u, W);
	else add(x, u, W);
}
int main()
{
	cnt = 1;
	rep(i, 0, 20) fat[1][i] = 1;
	init(1, 0);
	Q = read();
	last = 0;
	while(Q --)
	{
		int op = read();
		p = read1();
		q = read1();
		if(op == 1)
		{
			int R = p ^ last, W = q ^ last;
			add(R, W);
		}
		else
		{
			int R = p ^ last;
			ll X = q ^ last;
			printf("%d\n", last = query(R, X));
		}
	}
	return 0;
}