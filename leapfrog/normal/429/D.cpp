//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
struct node{int x,y;char operator<(node b) const {return y<b.y;}}a[200005];
inline ll operator^(node a,node b) {return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);}
int n,cnt,t[200005];ll rs=1e18;//(i-j)^2+(si-sj)^2
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].x),a[i].x+=a[i-1].x,a[i].y=i;
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) for(int j=i+1;j<=n&&j<=i+10000;j++) rs=min(rs,a[i]^a[j]);
	return printf("%lld\n",rs),0;
}