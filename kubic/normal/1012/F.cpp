#include <bits/stdc++.h>
using namespace std;
#define N 25
#define M 1<<22
const int INF=0x3f3f3f3f;
int n,m,all,stt=-1,dp[M],pr[M],ans[N];
struct Node {int id,l,r,w;}a[N],a1[N],a2[N];
bool cmp1(Node x,Node y) {return x.l<y.l;} 
bool cmp2(Node x,Node y) {return x.w<y.w;}
int main()
{
	scanf("%d %d",&n,&m);all=(1<<n)-1;
	dp[0]=1;for(int i=1;i<1<<n;++i) dp[i]=INF; 
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d",&a[i].l,&a[i].r,&a[i].w);
		a[i].r+=a[i].l-1;a[i].id=i;a1[i]=a2[i]=a[i];
	}sort(a1+1,a1+n+1,cmp1);sort(a2+1,a2+n+1,cmp2);
	for(int i=0,t,ps1,ps2;i<=all;++i) if(dp[i]<INF) 
	{
		t=dp[i];ps1=ps2=1;
		for(int j=1,id=a2[j].id;j<=n;++j,id=a2[j].id) if(!(i>>id-1&1))
		{
			while(1)
			{
				while(ps1<=n && (a1[ps1].r<t || !(i>>a1[ps1].id-1&1))) ++ps1;
				while(ps2<=n && a1[ps2].r<t) ++ps2;
				if(ps1<=n && t+a2[j].w>=a1[ps1].l) t=a1[ps1].r+1;
				else if(ps2<=n && t>=a1[ps2].l) t=a1[ps2].r+1;else break;
			}
			if(t+a2[j].w<min(a2[j].l,dp[i|(1<<id-1)]))
				dp[i|(1<<id-1)]=t+a2[j].w,pr[i|(1<<id-1)]=id;
		}
	}
	if(m==1)
	{
		if(dp[all]>=INF) {puts("NO");return 0;}puts("YES");
		for(int i=all;i;i^=(1<<pr[i]-1)) ans[pr[i]]=dp[i]-a[pr[i]].w;
		for(int i=1;i<=n;++i) printf("1 %d\n",ans[i]);
	}
	else
	{
		for(int i=0;i<=all;++i) if(dp[i]<INF && dp[all^i]<INF) {stt=i;break;}
		if(stt==-1) {puts("NO");return 0;}puts("YES");
		for(int i=stt;i;i^=(1<<pr[i]-1)) ans[pr[i]]=dp[i]-a[pr[i]].w;
		for(int i=all^stt;i;i^=(1<<pr[i]-1)) ans[pr[i]]=dp[i]-a[pr[i]].w;
		for(int i=1;i<=n;++i) printf("%d %d\n",(stt>>i-1&1)+1,ans[i]);
	}return 0;
}