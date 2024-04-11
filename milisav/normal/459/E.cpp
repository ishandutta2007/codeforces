#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;
struct grana
{
	int u,v,w;
};
bool operator <(grana x, grana y)
{
	return x.w<y.w;
}
stack<int> s;
grana a[3000000];
int p[3000000][2];
int n,m;
int r;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		p[i][0]=0;
		p[i][1]=0;
	}
	for(int i=0;i<m;i++) scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	sort(a,a+m);
	p[a[0].v][1]=1;
	s.push(a[0].v);
	r=1;
	for(int i=1;i<m;i++)
	{
		if(a[i].w==a[i-1].w)
		{
			s.push(a[i].v);
		}
		else
		{
			while(s.size()>0)
			{
				p[s.top()][0]=p[s.top()][1];
				s.pop();
			}
			s.push(a[i].v);
		}
		p[a[i].v][1]=max(p[a[i].v][1],p[a[i].u][0]+1);
		r=max(r,p[a[i].v][1]);
	}
	printf("%d",r);
	return 0;
}