#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,lg[N],a[N],st1[N],st2[N],st3[N],st4[N],tg[N],ps[N],ps1[N];
struct Node {int x,x1,x2;}z[N];
struct BitArray
{
	int vl[N];
	void upd(int x,int w) {for(;x<=n;x+=x&-x) vl[x]=max(vl[x],w);}
	int qMx(int x) {int res=0;for(;x;x-=x&-x) res=max(res,vl[x]);return res;}
}BIT;
struct RangeQuery
{
	int a[N],mx[18][N];
	void build()
	{
		for(int i=1;i<=n;++i) mx[0][i]=i;
		for(int i=1,t1,t2;i<=lg[n];++i) for(int j=1;j+(1<<i)-1<=n;++j)
			t1=mx[i-1][j],t2=mx[i-1][j+(1<<i-1)],mx[i][j]=a[t1]>a[t2]?t1:t2;
	}
	int qMx(int l,int r)
	{int t=lg[r-l+1],t1=mx[t][l],t2=mx[t][r-(1<<t)+1];return a[t1]>a[t2]?t1:t2;}
}RMQ1,RMQ2;
int main()
{
	scanf("%d %d",&n,&m);for(int i=2;i<=n;++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),RMQ1.a[i]=a[i],RMQ2.a[i]=-a[i];
	RMQ1.build();RMQ2.build();
	for(int i=1,t,t1,t2;i<=n;++i)
	{
		while(st1[0] && a[i]>a[st1[st1[0]]])
		{t=st1[st1[0]--];--tg[t];if(!tg[t]) BIT.upd(t,t);}
		while(st2[0] && a[i]<a[st2[st2[0]]])
		{t=st2[st2[0]--];--tg[t];if(!tg[t]) BIT.upd(t,t);}
		while(st3[0] && a[i]>=a[st3[st3[0]]]) --st3[0];
		while(st4[0] && a[i]<=a[st4[st4[0]]]) --st4[0];
		t=BIT.qMx(min(st3[st3[0]],st4[st4[0]]));
		t1=RMQ1.qMx(t,i);t2=RMQ2.qMx(t,i);if(t1>t2) swap(t1,t2);
		z[i]=(Node) {t,t1,t2};tg[i]=2;
		st1[++st1[0]]=i;st2[++st2[0]]=i;st3[++st3[0]]=i;st4[++st4[0]]=i;
	}for(int i=1;i<=n;++i) RMQ1.a[i]=z[i].x;RMQ1.build();
	for(int i=1;i<n;++i)
	{
		ps1[i]=a[i]==a[i-1]?ps1[i-1]:i-1;if(!ps1[i]) continue;
		if(a[i]<a[ps1[i]] && a[i]<a[i+1]) ps[i+1]=i;
		else if(a[i]>a[ps1[i]] && a[i]>a[i+1]) ps[i+1]=i;else ps[i+1]=ps[i];
	}
	for(int i=1,l,r,t;i<=m;++i)
	{
		scanf("%d %d",&l,&r);t=RMQ1.qMx(l,r);
		if(z[t].x>=l) printf("4\n%d %d %d %d\n",z[t].x,z[t].x1,z[t].x2,t);
		else if(ps1[ps[r]]>=l) printf("3\n%d %d %d\n",ps1[ps[r]],ps[r],ps[r]+1);
		else printf("0\n");
	}return 0;
}