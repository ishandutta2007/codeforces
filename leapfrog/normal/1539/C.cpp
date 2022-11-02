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
int n,cn=1;ll K,X,a[200005],b[200005];
int main()
{
	read(n),read(K),read(X);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<n;i++) b[i]=max(0ll,(a[i+1]-a[i]-1)/X);
	//for(int i=1;i<n;i++) printf("%lld%c",b[i],i==n-1?'\n':' ');
	sort(b+1,b+n);for(int i=1;i<n;i++) if(b[i]) cn++;
	for(int i=1;i<n;i++) if(b[i]&&K>=b[i]) K-=b[i],cn--;
	return printf("%d\n",cn),0;
}