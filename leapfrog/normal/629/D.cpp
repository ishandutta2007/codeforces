//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n;ll T[100005],dp[100005];const double pi=acos(-1);
struct node{ll v;int id;char operator<(node b) const {return v^b.v?v<b.v:id>b.id;}}a[100005];
inline void add(int x,ll w) {for(;x<=n;x+=x&(-x)) if(T[x]<w) T[x]=w;else return;}
inline ll qry(int x) {ll r=0;for(;x;x-=x&(-x)) r=max(r,T[x]);return r;}
int main()
{
	read(n);for(int i=1,r,h;i<=n;i++) read(r),read(h),a[i]=(node){1ll*r*r*h,i};
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) add(a[i].id,dp[i]=qry(a[i].id-1)+a[i].v);
	ll rs=0;for(int i=1;i<=n;i++) rs=max(rs,dp[i]);
	return printf("%.10lf\n",rs*pi),0;
}