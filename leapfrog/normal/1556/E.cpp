#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,Q,lg[2000005];ll a[200005],st[200005][20],gt[200005][20];
int main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x;i<=n;i++) read(x),a[i]=x-a[i],a[i]+=a[i-1];
	//for(int i=1;i<=n;i++) printf("%lld%c",a[i]-a[i-1],i==n?'\n':' ');
	for(int i=1;i<=n;i++) st[i][0]=a[i],gt[i][0]=a[i];
	for(int j=1;j<20;j++) for(int i=1;i+(1<<(j-1))<=n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int j=1;j<20;j++) for(int i=1;i+(1<<(j-1))<=n;i++) gt[i][j]=min(gt[i][j-1],gt[i+(1<<(j-1))][j-1]);
	lg[0]=-1;for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int l,r;Q--;)
	{
		read(l),read(r);int g=lg[r-l+1];
		ll mx=max(st[l][g],st[r-(1<<g)+1][g])-a[l-1];
		ll mn=min(gt[l][g],gt[r-(1<<g)+1][g])-a[l-1];
		if(a[r]-a[l-1]!=0) {puts("-1");continue;}
		if(mn<0) puts("-1");else printf("%lld\n",mx);
	}
	return 0;
}