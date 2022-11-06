#include<bits/stdc++.h>
#define re register
int N,M,n,m,x[100100],y[100100];
std::vector<int>x1[200100],yy1[200100];
std::pair<int,bool>pp[200100];
#define mp(a,b) std::make_pair(a,b)
int gcd(re int a,re int b){return b?gcd(b,a%b):a;}
void exgcd(re int a,re int b,re int&x,re int&y)
{
	if(b==0)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
int main()
{
	re long long ans1=0;
	scanf("%d%d",&N,&M);
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&x[i]);
	scanf("%d",&m);
	for(re int i=1;i<=m;i++)scanf("%d",&y[i]);
	re int g=gcd(N,M);
	if(g>n+m){puts("-1");return 0;}
	for(re int i=1;i<=n;i++)x1[x[i]%g].push_back(x[i]/g);
	for(re int i=1;i<=m;i++)yy1[y[i]%g].push_back(y[i]/g);
	N/=g;M/=g;
	re int n1,m1;
	exgcd(N,M,n1,m1);
	n1=(n1+M)%M;m1=(m1+N)%N;
	for(re int i=0;i<g;i++)
	{
		for(re int j=0;j<x1[i].size();j++)x[j+1]=x1[i][j];
		for(re int j=0;j<yy1[i].size();j++)y[j+1]=yy1[i][j];
		n=x1[i].size();m=yy1[i].size();
		if(n+m==0){puts("-1");return 0;}
		if(n==N&&m==M)continue;
		re int cnt=0;
		re long long ans=0;
		for(re int i=1;i<=n;i++)pp[++cnt]=mp(1ll*m1*x[i]%N,1);
		for(re int i=1;i<=m;i++)pp[++cnt]=mp(1ll*m1*y[i]%N,0);
		std::sort(pp+1,pp+cnt+1);
		pp[++cnt]=pp[1];pp[cnt].first+=N;
		for(re int i=1;i<cnt;i++)
		{
			if((pp[i].second==0&&pp[i].first!=pp[i+1].first)||(pp[i].first<pp[i+1].first-1))
			{
				ans=std::max(ans,1ll*(pp[i+1].first-1-pp[i].first)*M+1ll*M*pp[i].first%N);
			}
		}
		cnt=0;
		for(re int i=1;i<=n;i++)pp[++cnt]=mp(1ll*n1*x[i]%M,0);
		for(re int i=1;i<=m;i++)pp[++cnt]=mp(1ll*n1*y[i]%M,1);
		std::sort(pp+1,pp+cnt+1);
		pp[++cnt]=pp[1];pp[cnt].first+=M;
		for(re int i=1;i<cnt;i++)
		{
			if((pp[i].second==0&&pp[i].first!=pp[i+1].first)||(pp[i].first<pp[i+1].first-1))
			{
				ans=std::max(ans,1ll*(pp[i+1].first-1-pp[i].first)*N+1ll*N*pp[i].first%M);
			}
		}
		ans1=std::max(ans1,ans*g+i);
	}
	printf("%lld\n",ans1);
}