#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define LIM 1000000
#define db double
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char buf[LIM],*P1,*P2;
int n;db dp[N],nw[N],a[N][N];bool vs[N]; 
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
db calc(int u) {return (dp[u]+nw[u])/(1-nw[u]);}
void release(int u)
{
	vs[u]=1;
	for(int i=1;i<=n;++i) if(!vs[i])
		dp[i]+=(calc(u)+1)*a[i][u]*nw[i],nw[i]*=1-a[i][u];
}
int main()
{
	n=rd();for(int i=1;i<n;++i) nw[i]=1;
	for(int i=1,x;i<=n;++i) for(int j=1;j<=n;++j)
		x=rd(),a[i][j]=0.01*x;release(n);
	for(int i=1,t=0;i<n;++i,t=0)
	{
		for(int j=1;j<=n;++j)
			if(!vs[j] && (!t || calc(j)<calc(t))) t=j;
		if(t==1) break;release(t);
	}printf("%.10lf\n",calc(1));return 0;
}