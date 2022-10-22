#include <bits/stdc++.h>
using namespace std;
#define N 15
#define N1 1<<7
#define M 1000005
#define MOD 1000000007
#define MOD1 9999997
#define ulll __uint128_t
#define pct __builtin_popcount
int n,ans,cntT,w[N1],a[N][N];ulll all[N],z[N1];
int cntH,hd[MOD1];struct Node {int w,nxt;ulll x;}hs[M],tmp[M];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void ins(ulll x)
{int t=x%MOD1;hs[++cntH]=(Node) {0,hd[t],x};hd[t]=cntH;}
int find(ulll x)
{
	int t=x%MOD1;
	for(int i=hd[t];i;i=hs[i].nxt)
		if(x==hs[i].x) return i;return 0;
}
void upd(ulll x,int w)
{int t=find(x);if(!t) ins(x),t=cntH;W(hs[t].w,w);}
int main()
{
	scanf("%d",&n);upd(1,1);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		scanf("%d",&a[i][j]);
	for(int i=0;i<1<<n;++i) all[pct(i)]|=(ulll)(1)<<i;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=cntH;++j)
			tmp[++cntT]=hs[j],hd[hs[j].x%MOD1]=0;cntH=0;
		for(int j=0;j<1<<n;++j)
		{
			w[j]=1;
			for(int k=1;k<=n;++k)
				if(j>>k-1&1) w[j]=1ll*w[j]*a[i][k]%MOD;
				else w[j]=1ll*w[j]*(100-a[i][k])%MOD;
		}
		for(int j=1;j<=cntT;++j)
		{
			for(int k=1;k<1<<n;++k) z[k]=z[k&k-1]|(tmp[j].x<<(k&-k));
			for(int k=0;k<1<<n;++k)
			{z[k]&=all[i];if(z[k]) upd(z[k],1ll*tmp[j].w*w[k]%MOD);}
		}cntT=0;
	}printf("%lld\n",1ll*hs[1].w*qPow(100,MOD-n*n-1)%MOD);return 0;
}