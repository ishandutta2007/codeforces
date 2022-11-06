#include <bits/stdc++.h>
using namespace std;
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)
 
struct point
{	
	int x, y; bool out;
	inline point(int _x, int _y, bool _out) :x(_x), y(_y), out(_out){}
	inline point() :x(0), y(0), out(0){}
};
 
int n, m, q;
struct pt
{
	point tar[12];
};
inline pt operator *(const pt a, const pt b)
{
	pt ans;
	for(int i = 1; i <= m; i ++)
		if(b.tar[i].out) ans.tar[i] = b.tar[i]; 
		else ans.tar[i] = a.tar[b.tar[i].y];
	return ans;
}
 
char mp[100086][12], *cmp; 
bool vis[12]; 
pt cd;

inline point calc(int x, int y)
{
	point &ans = cd.tar[y];
	if(!vis[y])
	{
		vis[y] = 1;
		if(cmp[y] == '<')
		{
			if(y == 1) ans = point(x, 0, 1); 
			else ans = calc(x, y - 1);
		}
		else if(cmp[y] == '>')
		{
			if(y == m) ans = point(x, m + 1, 1); 
			else ans = calc(x, y + 1);
		}
		else ans = point(x - 1, y, 0);
	}
	return ans;
}

inline pt calc(int x)
{
	memset(vis, 0, sizeof(vis));
	cmp = mp[x];
	for(int i = 1; i <= m; i ++)
		cd.tar[i] = point(-1, -1, 1);
	for(int i = 1; i <= m; i ++) 
		if(!vis[i]) 
			calc(x, i);
	return cd;
}
 
struct node
{
	node *ls, *rs;
	int l, r, m;
	pt data;
	inline void chg(int x)
	{
		if(l == r) data = calc(l);
		else
		{
			if(x <= m) ls -> chg(x); 
			else rs -> chg(x);
			data = ls -> data * rs -> data;
		}
	}
	inline point query(int x, int y)
	{
		if(x == r) return data.tar[y];
		else if(x <= m) return ls -> query(x, y);
		else
		{
			point tmp = rs -> query(x, y);
			if(tmp.out) return tmp; 
			else return ls -> data.tar[tmp.y];
		}
	}
} pool[200010], *cp = pool;

inline node *Build(int ll, int rr)
{
	node *ans = cp ++;
	ans -> l = ll; 
	ans -> r = rr; 
	ans -> m = ((ll + rr) >> 1);
	if(ll == rr)
	{
		ans -> ls = ans -> rs = NULL;
		ans -> data = calc(ll);
	}
	else
	{
		ans -> ls = Build(ll, ans -> m);
		ans -> rs = Build(ans -> m + 1, rr);
		ans -> data = ans -> ls -> data * ans -> rs -> data;
	}
	return ans;
}
 
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i ++)
		scanf("%s", mp[i] + 1);
	node *root = Build(1, n);
	while(q --)
	{
		char op[4]; 
		int x, y; 
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'A')
		{
			point ans = root -> query(x, y); 
			printf("%d %d\n", ans.x, ans.y);
		}
		else
		{
			char c[4]; 
			scanf("%s", c);
			mp[x][y] = c[0]; 
			root -> chg(x);
		}
	}
	return 0;
}