#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pi complex<ld>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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

const int N = 100010;
int n,m,h,w[N],cnt,head[N];
struct Node
{
	int to, next;
}e[N * 2];
void insert(int x,int y)
{
	e[++ cnt].to = y;
	e[cnt].next = head[x];
	head[x] = cnt;
}
int tot, dfn[N], low[N], stk[N], top;
bool instk[N];
int bln, belong[N], sz[N], du[N];
void tarjan(int x)
{
	dfn[x] = low[x] = ++ tot;
	stk[++ top] = x; 
	instk[x] = 1;
	for(int i = head[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if(!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
		else if(instk[y]) low[x] = min(low[x], dfn[y]);
	}
	if(dfn[x] == low[x])
	{
		bln ++;
		while(1)
		{
			sz[bln] ++;
			int X = stk[top];
			belong[X] = bln;
			stk[top --] = 0;
			instk[X] = 0;
			if(x == X) break;
		}
	}
}
int main()
{
	n = read();
	m = read();
	h = read();

	rep(i, 1, n) w[i] = read();
	rep(i, 1, m)
	{
		int c1 = read(), c2 = read();
		if((w[c1] + 1) % h == w[c2]) insert(c1, c2);
		if((w[c2] + 1) % h == w[c1]) insert(c2, c1);
	}
	rep(i, 1, n)
		if(!dfn[i])
			tarjan(i);
	rep(x, 1, n)
		for(int i = head[x]; i; i = e[i].next)
		{
			int y = e[i].to;
			if(belong[x] != belong[y]) du[belong[x]] ++;
		}
	int ans = 0;
	sz[0] = 1e9;
	rep(i, 1, bln)
		if(!du[i] && sz[i] < sz[ans])
			ans = i;
	cout << sz[ans] << endl;
	rep(i, 1, n)
		if(belong[i] == ans)
			printf("%d ",i);
	return 0;
}