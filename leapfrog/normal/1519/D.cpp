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
int n,a[10005],b[10005];ll ans=0,sum=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i*2-1]);
	for(int i=1;i<=n;i++) read(b[i*2-1]);
	n=n*2;for(int i=1;i<=n;i++) ans=sum=sum+1ll*a[i]*b[i];
	for(int i=1;i<=n;i++)
	{
		ll res=sum;
		for(int l=1;l<=i&&l<=n-i;l++)
		{
			res-=1ll*a[i-l]*b[i-l]+1ll*a[i+l]*b[i+l];
			res+=1ll*a[i-l]*b[i+l]+1ll*a[i+l]*b[i-l];
			ans=max(ans,res);
		}
	}
	return printf("%lld\n",ans),0;
}