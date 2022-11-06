#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int Rand(int l,int r)
{
	return rand()%(r-l+1)+l;
}
struct point
{
	int x,y;
	inline point operator-(point th)
	{
		return point{x-th.x,y-th.y};
	}
};
inline int dot(point p,point q)
{
	return p.x*q.x+p.y*q.y;
}
inline int det(point p,point q)
{
	return p.x*q.y-q.x*p.y;
}
const int N=1e5+5;
int n;
struct cell
{
	point p;
	int id;
}c[N];
int p[N];
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",c[i].id);
		putchar('\n');
		exit(0);
		return;
	}
	register int i;
	for(i=x;i<=n;i++)
	{
		swap(c[x],c[i]);
		if(x>=3&&dot(c[x-1].p-c[x-2].p,c[x].p-c[x-1].p)>=0)
		{
			swap(c[x],c[i]);
			continue;
		}
		dfs(x+1);
		swap(c[x],c[i]);
	}
	return;
}
signed main()
{
	point x,y,z;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&c[i].p.x,&c[i].p.y),c[i].id=i;
	random_shuffle(c+1,c+n+1);
	dfs(1);
	return 0;
}