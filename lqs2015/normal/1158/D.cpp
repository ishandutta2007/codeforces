#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
}p[2222];
point operator - (const point &u,const point &v) 
{
	point res;
	res.x=u.x-v.x;
	res.y=u.y-v.y;
	return res;
}
long long cross(point u,point v)
{
	return (1ll*u.x*v.y-1ll*u.y*v.x);
}
int n,cur,ans[2222],cnt,to;
char s[2222];
bool used[2222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	scanf("%s",s);
	cur=1;
	for (int i=2;i<=n;i++)
	{
		if (p[i].x<p[cur].x || (p[i].x==p[cur].x && p[i].y<p[cur].y)) cur=i;
	}
	used[cur]=1;ans[cnt=1]=cur;
	for (int i=1;i<n;i++)
	{
		to=-1;
		for (int j=1;j<=n;j++)
		{
			if (used[j]) continue;
			if (to==-1) to=j;
			else 
			{
				if (s[i-1]=='L')
				{
					if (cross(p[to]-p[cur],p[j]-p[cur])<0) to=j; 
				} 
				else
				{
					if (cross(p[to]-p[cur],p[j]-p[cur])>0) to=j; 
				}
			}
		}
		used[to]=1;ans[++cnt]=to;
		cur=to;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}