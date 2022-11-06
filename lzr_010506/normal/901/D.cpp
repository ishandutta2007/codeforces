#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define InF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
const int N = 100000 + 10;
const int M = 200000 + 10;
int n, m;
int cnt = 1, head[N], next[M], to[M];
int Dep[N];
int X, Y, id;
ll sumx, sumy, ans[M], c[N];
bool visited[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
void ins(int x, int y)
{
	next[++ cnt] = head[x];
	to[cnt] = y;
	head[x] = cnt;
}

inline void insert(int x, int y)
{
	ins(x, y);
	ins(y, x);
}

void Dfs(int x)
{
	for(int i = head[x]; i; i = next[i])
		if(!Dep[to[i]]) Dep[to[i]] = Dep[x] + 1, Dfs(to[i]);
		else
			if(!(Dep[x] - Dep[to[i]] & 1))
				X = x, Y = to[i], id = i >> 1;
}

void solve(int x)
{
	visited[x] = 1;
	for(int i = head[x]; i; i = next[i])
		if(!visited[to[i]])
			solve(to[i]), ans[i >> 1] = c[to[i]], c[x] -= ans[i >> 1];
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) c[i] = read();
	rep(i, 1, m)
	{
		int x = read();
		int y = read();
		insert(x, y);
	}
	Dep[1] = 1;
	Dfs(1);
	rep(i, 1, n)
		(Dep[i] & 1 ? sumx : sumy) += c[i];
	if(sumx != sumy && !id)
		return 0 * puts("NO");
	ll x = (sumx - sumy) >> 1;
	(Dep[X] & 1) ? ans[id] = x : ans[id] = -x;
	c[X] -= ans[id], c[Y] -= ans[id];
	solve(1);
	puts("YES");
	rep(i, 1, m)
		printf("%I64d\n", ans[i]);
	return 0;
}