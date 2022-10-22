#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 1000000007
int n,ans=1,a[N],p[N],vs[N],w[N],cnt1[N],cnt2[N],ps1[N],ps2[N],tp[N],st[N][10];
void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) vs[i]=p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j) {vs[i*p[j]]=p[j];if(!(i%p[j])) break;}
	}
}
int main()
{
	scanf("%d",&n);sieve(n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=p[0];++i) ++cnt2[n/p[i]];
	for(int i=1;i<=n;++i)
	{
		w[i]=1;if(i==1) {st[1][tp[1]++]=1;++cnt2[1];continue;}
		for(int j=i,lst=0;j>1;j/=vs[j])
			if(vs[j]!=lst) w[i]*=vs[j],lst=vs[j],st[i][tp[i]++]=vs[j];
	}for(int i=1;i<=n;++i) ++cnt1[w[i]];
	for(int i=1,t1,t2,w1,w2;i<=n;++i) if(a[i])
	{
		if(tp[i]!=tp[a[i]]) {puts("0");return 0;}--cnt1[w[i]];
		for(int j=0;j<tp[i];++j)
		{
			t1=st[i][j];t2=st[a[i]][j];w1=t1>1?n/t1:1;w2=t2>1?n/t2:1;
			if(w1!=w2) {puts("0");return 0;}
			if(ps1[t1] && ps1[t1]!=t2) {puts("0");return 0;}
			if(ps2[t2] && ps2[t2]!=t1) {puts("0");return 0;}
			if(!ps1[t1]) ps1[t1]=t2,ps2[t2]=t1,--cnt2[w1];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=2;j<=cnt1[i];++j) ans=1ll*ans*j%MOD;
		for(int j=2;j<=cnt2[i];++j) ans=1ll*ans*j%MOD;
	}printf("%d\n",ans);return 0;
}