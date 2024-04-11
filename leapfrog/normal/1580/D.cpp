//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=4005;int n,m,id;ll a[N],dp[N][N];
inline void upd(ll &a,ll b) {a<b?a=b:a;}
inline int solve(int l,int r)
{
	if(l>r) return 0;else if(l==r) return dp[++id][1]=a[l]*(m-1),id;
	int wh=l;for(int i=l+1;i<=r;i++) if(a[i]<a[wh]) wh=i;
	int ld=solve(l,wh-1),rd=solve(wh+1,r),lz=wh-l,rz=r-wh;id++;
	for(int i=0;i<=lz;i++) for(int j=0;j<=rz;j++)
	{
		upd(dp[id][i+j],dp[ld][i]+dp[rd][j]-2ll*i*j*a[wh]);
		upd(dp[id][i+j+1],dp[ld][i]+dp[rd][j]+(m-1)*a[wh]-2ll*(i*j+i+j)*a[wh]);
	}return id;
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(a[i]);
	return printf("%lld\n",dp[solve(1,n)][m]),0;
}