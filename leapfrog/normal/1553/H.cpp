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
int N,n,F[524289],mx[524289],mn[524289];const int INF=1e9;
int main()
{
	read(N),read(n);for(int i=0;i<(1<<n);i++) mn[i]=F[i]=INF,mx[i]=-INF;
	for(int i=1,x;i<=N;i++) read(x),mx[x]=mn[x]=0;
	for(int d=0;d<n;d++) for(int r=0;r<(1<<n);r++) if((r>>d)&1)
	{
		int l=r-(1<<d);F[l]=F[r]=min(F[l],F[r]);
		F[l]=min(F[l],mn[r]-mx[l]+(1<<d)),F[r]=min(F[r],mn[l]-mx[r]+(1<<d));
		int mnl=mn[l],mnr=mn[r],mxl=mx[l],mxr=mx[r];
		mn[l]=min(mnl,mnr+(1<<d)),mn[r]=min(mnr,mnl+(1<<d));
		mx[l]=max(mxl,mxr+(1<<d)),mx[r]=max(mxr,mxl+(1<<d));
	}
	for(int i=0;i<(1<<n);i++) printf("%d ",F[i]);
	return putchar('\n'),0;
}