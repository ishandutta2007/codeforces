#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=50;
const double INF=5e9;
const double eps=1e-6;
double f[N+5][N+5][N+5];
struct node
{
	double a,b;
}t[N+5]; 
int n;
bool cmp(node a,node b)
{
	return a.a>b.a;
}
bool check(double x)
{
	for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) for(int k=0;k<=n+1;k++) f[i][j][k]=INF;
	f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(t[i].a==t[i-1].a) 
				{
					if(k-1>=0&&f[i-1][j][k-1]!=INF) f[i][j][k]=min(f[i][j][k],f[i-1][j][k-1]+t[i].a-x*t[i].b);
					if(f[i-1][j+1][k]!=INF) f[i][j][k]=min(f[i][j][k],f[i-1][j+1][k]);
				}
				else
				{
					if(j-k+1>=0&&f[i-1][j-k+1][k]!=INF) f[i][j][0]=min(f[i][j][0],f[i-1][j-k+1][k]);
					if(j-k>=0&&f[i-1][j-k][k]!=INF) f[i][j][1]=min(f[i][j][1],f[i-1][j-k][k]+t[i].a-x*t[i].b);
				}
			}
		}
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) if(f[n][i][j]<=0) return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&t[i].a);
	for(int i=1;i<=n;i++) scanf("%lf",&t[i].b);
	t[0].a=INF;
	sort(t,t+n+1,cmp);
	double l=0,r=INF;
	while(r-l>=eps)
	{
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	l*=1000;
	ll ans=ceil(l);
	printf("%lld\n",ans);
	return 0;
}