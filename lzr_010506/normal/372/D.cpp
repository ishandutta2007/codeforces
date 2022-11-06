#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
typedef set<int>::iterator it;
#define N 110000
int n, limit;
int head[N],next[N*2],p[N*2],now;
int dx[N], xl[N], tot, f[N][20], dep[N], t1=0;
set<int> s;
int dis(int x,int y)
{
	if(x == y)return 0;
	int res = dep[x] + dep[y];
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 17; i >= 0 ; i --) 
		if((dep[x] - dep[y]) & (1 << i)) 
			x = f[x][i];
	if(x == y) return res - dep[y] * 2;
	for(int i = 17; i >= 0 ; i --) 
		if(f[x][i] != f[y][i]) 
			x = f[x][i], y = f[y][i];
	res -= dep[f[x][0]] * 2;
	return res;
}
void add(int x,int v)
{
	if(v > 0) s.insert(x);
	else s.erase(x);
}
inline void line(int a,int b)
{
	t1 ++;
	p[t1] = b;
	next[t1] = head[a];
	head[a] = t1;
}
void dfs(int x)
{
	dx[x] = ++ tot; 
	xl[tot] = x;
	dep[x] = dep[f[x][0]] + 1;
	for(int u = head[x]; u; u = next[u])
	if(p[u] != f[x][0])
	{
		f[p[u]][0] = x;
		dfs(p[u]);
	}
}
inline int calc(int x)
{
	it A,B,C;
	A = s.lower_bound(dx[x]);
	B = A;
	C = A;
	if(B == s.begin()) B = s.end();
	B --;
	C ++;
	if(C == s.end()) C = s.begin();
	return dis(x,xl[*C]) + dis(x, xl[*B]) - dis(xl[*B], xl[*C]);
}
inline int DEL(int x)
{
	now -= calc(x);
	add(dx[x], -1);
}
inline int ADD(int x)
{
	add(dx[x], 1);
	now += calc(x);
}
int main()
{
	scanf("%d%d",&n,&limit);
	limit *= 2;
	limit -= 2;
	for(int i = 1; i < n; i ++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		line(a,b);
		line(b,a);
	}
	dfs(1);
	for(int j = 1; j <= 17; j ++)
		for(int i = 1; i <= n; i ++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	int r=1;
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		while(r <= n && limit >= now) {ADD(r); r ++;}
		if(now <= limit && r == n + 1){ans = max(ans, r - i); break;}
		ans = max(ans, r - i - 1);
		DEL(i);
	}
	printf("%d\n",ans);
}