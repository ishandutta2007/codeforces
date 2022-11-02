#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=14,M=105,K=1<<14,inf=1e9+7;
int n,m,nn,ans,d1[K][M],d2[K][N],d3[M][M],f[K][M],g[K][M];
struct P{int x,y,t;}a[N],b[M];
inline bool cmp(P a,P b){return a.t<b.t;} 
inline int d(P a,P b){return abs(a.x-b.x)+abs(a.y-b.y);}
int main()
{
	n=rd();m=rd();nn=1<<n;ans=1;
	rep0(i,0,n)a[i].x=rd(),a[i].y=rd();
	rep(i,1,m)b[i].x=rd(),b[i].y=rd(),b[i].t=rd();
	std::sort(b+1,b+m+1,cmp);
	rep0(s,0,nn)
	{
		rep(i,0,m)f[s][i]=inf;
		rep(i,1,m)g[s][i]=-inf;
		rep(i,1,m)d1[s][i]=inf;
		rep0(i,0,n)d2[s][i]=inf;
		rep(i,1,m)rep0(j,0,n)if(s>>j&1)cmn(d1[s][i],d(b[i],a[j]));
		rep0(i,0,n)rep0(j,0,n)if(s>>j&1)cmn(d2[s][i],d(a[i],a[j]));
	}
	rep(i,1,m)rep(j,1,m)d3[i][j]=d(b[i],b[j]);
	rep0(i,0,n)f[1<<i][0]=0;
	rep(i,1,m)g[0][i]=1;
	rep0(s,0,nn)
	{
		rep(i,0,m)if(f[s][i]!=inf)
		{
			rep0(j,0,n)if(~s>>j&1)cmn(f[s|(1<<j)][i],f[s][i]+d2[s][j]);
			rep(j,1,m)if(f[s][i]+d1[s][j]<=b[j].t)cmx(g[s][j],i+1);
		}
		rep(i,1,m)if(g[s][i]!=-inf)
		{
			rep0(j,0,n)if(~s>>j&1)cmn(f[s|(1<<j)][g[s][i]],b[i].t+std::min(d2[s][j],d(b[i],a[j])));
			rep(j,i+1,m)if(b[i].t+std::min(d1[s][j],d3[i][j])<=b[j].t)cmx(g[s][j],g[s][i]+1);
		}
	}
	rep0(s,0,nn)rep(i,1,m)cmx(ans,g[s][i]);
	printf("%d\n",ans);return 0;
}