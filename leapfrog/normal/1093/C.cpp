//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int n;ll b[100005],a[200005];
int main()
{
	read(n),n>>=1;for(int i=1;i<=n;i++) read(b[i]);
	a[1]=0,a[n+n]=b[1];for(int i=2;i<=n;i++)
	{
		a[n+n-i+1]=min(b[i],a[n+n-i+2]),a[i]=b[i]-a[n+n-i+1];
		if(a[i]<a[i-1]) a[i]=a[i-1],a[n+n-i+1]=b[i]-a[i];
	}
	for(int i=1;i<=n+n;i++) printf("%lld%c",a[i],i==n+n?'\n':' ');
	return 0;
}