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
int n,m;ll a[1005][1005],s1[1005],s2[1005],K,p,rs=-1e18;
priority_queue<int>q1,q2;ll v1[1000005],v2[1000005];
int main()
{
	read(n,m,K,p);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s1[i]+=a[i][j],s2[j]+=a[i][j];
	for(int i=1;i<=n;i++) q1.push(s1[i]);
	for(int i=1,v;i<=K;i++) v1[i]=v1[i-1]+(v=q1.top()),q1.pop(),q1.push(v-p*m);
	for(int i=1;i<=m;i++) q2.push(s2[i]);
	for(int i=1,v;i<=K;i++) v2[i]=v2[i-1]+(v=q2.top()),q2.pop(),q2.push(v-p*n);
	for(int i=0;i<=K;i++) rs=max(rs,v1[i]+v2[K-i]-p*i*(K-i));
	return printf("%lld\n",rs),0;
}