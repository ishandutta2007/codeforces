//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,K,a[100005],nx[100005],tn[100005],d[100005],L[100005],R[100005];char vs[100005];
int main()
{
	read(n),read(K);for(int i=1;i<=n*K;i++) read(a[i]);
	for(int i=1;i<=n*K;i++) nx[tn[a[i]]]=i,tn[a[i]]=i;
	for(int k=1;k<=(n+K-1-1)/(K-1);k++)
	{
		int tt=0,l=(k-1)*(K-1)+1,r=k*(K-1),nw=0;r=min(r,n);
		for(int i=1;i<=n*K;i++) if(l<=a[i]&&a[i]<=r) tn[++tt]=i;
		for(int i=1;i<=r-l+1;i++)
		{
			int mn=n*K+1,mnw=114;
			for(int j=nw+1;j<=tt;j++) if(!vs[a[tn[j]]]&&!d[a[tn[j]]]) d[a[tn[j]]]=nx[tn[j]];
			for(int j=l;j<=r;j++) if(!vs[j]&&d[j]<mn) mn=d[j],mnw=j;
			vs[mnw]=1;int wh=514;for(int j=nw+1;j<=tt;j++) if(a[tn[j]]==mnw) {wh=tn[j];break;}
			L[mnw]=wh,R[mnw]=mn;char fs=0;int nnx=0;
			for(int j=nw+1;j<=tt;j++) if(a[tn[j]]==mnw) {if(fs) {nnx=j;break;}else fs=1;}
			nw=nnx;for(int i=l;i<=r;i++) d[i]=0;
		}
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
	return 0;
}