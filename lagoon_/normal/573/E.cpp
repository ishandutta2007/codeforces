#include<bits/stdc++.h>
using namespace std;
#define re register
int a[100100],k[330],lb[100100],rb[100100],sz[100100],aa[100100],stk[330][330],ta[330],bt[330];
long long b[100100],bb[330];
bool bo[100100];
inline bool cmp(re int a1,re int a2){return a[a1]<a[a2];}
const int blk=320;
inline bool caj(re int a1,re int a2,re int a3)
{
	return (long double)(a[a2]-a[a1])*(b[a3]-b[a2])>=(long double)(a[a3]-a[a2])*(b[a2]-b[a1]);
}
void build(re int a)
{
	ta[a]=0;
	for(re int i=lb[a];i<=rb[a];i++)
	if(!bo[aa[i]]){
		while(ta[a]>=2&&caj(aa[i],stk[a][ta[a]],stk[a][ta[a]]-1))ta[a]--;
		while(ta[a]&&b[stk[a][ta[a]]]<=b[aa[i]])ta[a]--;
		stk[a][++ta[a]]=aa[i];
	}bt[a]=1;
}
int main()
{
	re int n,bk;
	re long long ans=0;
	scanf("%d",&n);bk=(n-1)/blk+1;
	for(re int i=1;i<=bk;i++)
	{
		lb[i]=(i-1)*blk+1;rb[i]=i*blk;if(rb[i]>n)rb[i]=n;sz[i]=rb[i]-lb[i]+1;
	}
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i],aa[i]=i;
	for(re int i=1;i<=bk;i++)sort(aa+lb[i],aa+rb[i]+1,cmp),build(i);
	for(re int i=1;i<=n;i++)
	{
		re long long mi=-1ll<<60;re int bnm=0,nm=0;
		for(re int j=1;j<=bk;j++)
		if(sz[j]){//printf("**%d %d\n",j,ta[j]);
			while(bt[j]<ta[j]&&b[stk[j][bt[j]]]+(long long)k[j]*a[stk[j][bt[j]]]<
			b[stk[j][bt[j]+1]]+(long long)k[j]*a[stk[j][bt[j]+1]])bt[j]++;
			if(b[stk[j][bt[j]]]+(long long)k[j]*a[stk[j][bt[j]]]+bb[j]>mi)
				mi=b[stk[j][bt[j]]]+(long long)k[j]*a[stk[j][bt[j]]]+bb[j],bnm=j,nm=stk[j][bt[j]];
		}//printf("%d %lld %d %d %lld %lld %lld\n",a[nm],mi,nm,bnm,b[nm],ans,b[nm]);
		if(mi<=0)break;
		ans+=mi;
		for(re int j=1;j<bnm;j++)bb[j]+=a[nm];
		for(re int j=bnm+1;j<=bk;j++)k[j]++;
		for(re int j=lb[bnm];j<nm;j++)b[j]+=(long long)a[j]*k[bnm]+bb[bnm]+a[nm];
		for(re int j=nm+1;j<=rb[bnm];j++)b[j]+=(long long)a[j]*(k[bnm]+1)+bb[bnm];
		k[bnm]=bb[bnm]=0;bo[nm]=1;sz[bnm]--;
		build(bnm);
	}printf("%lld\n",ans);
}