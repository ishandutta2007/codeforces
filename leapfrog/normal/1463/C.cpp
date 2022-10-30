//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int T,n,p,q,a[1000005],w[1000005],ans=0;
signed main()
{
	for(read(T);T--;)
	{
		read(n),ans=p=q=0;for(int i=1;i<=n;i++) read(a[i]),read(w[i]);
		for(int i=1,g;i<=n;i++)
		{
			if(p==q) q=w[i];
			if(a[i+1]-a[i]>abs(p-q)||i==n) g=q;
			else g=p+(p<q?1:-1)*(a[i+1]-a[i]);
			ans+=((w[i]-p)*(w[i]-g)<=0),p=g;
		}
		printf("%lld\n",ans);
	}
}