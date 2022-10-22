#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
const double eps=1e-10;
struct point
{
	double x,y;
}p[maxn+5];
int n,v[maxn+5];
int sgu(double x,double y)
{
	if(fabs(x-y)<eps) return 1;
	return 0;
}
double vec(point a,point o,point b)// ao->bo
{
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
int check(int a,int b,int c)
{
	if(sgu(vec(p[b],p[a],p[c]),0)) return 1;
	return 0;
}
void cer()
{
	memset(v,0,(n+5)*sizeof(int));
	return;
}
void solve(int a,int b)
{
	for(int i=1;i<=n;i++) if(check(a,b,i)) v[i]=1;
	return;
}
int chk()
{
	int a=-1,b=-1;
	for(int i=1;i<=n;i++) 
	{
		if(!v[i])
		{
			if(a==-1) a=i;
			else if(b==-1) b=i;
		}
	}
	solve(a,b);
	for(int i=1;i<=n;i++) if(!v[i]) return 0;
	return 1;
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=3;i++)
	{
		for(int j=i+1;j<=3;j++)
		{
			cer();
			solve(i,j);
			if(chk())
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
	
}