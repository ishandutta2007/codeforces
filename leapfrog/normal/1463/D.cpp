//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int T,n,a[2000005],v[4000005],ans=0;
signed main()
{
	for(read(T);T--;)
	{
		read(n),memset(v,0,sizeof(v));
		for(int i=1,w;i<=n;i++) read(w),v[w]=1;
		int le=0,w1=0;for(int i=1;i<=n+n;i++) if(v[i]) le++;else le--,w1=min(w1,le);
		int ri=0,w2=0;for(int i=n+n;i>=1;i--) if(v[i]) ri++;else ri--,w2=min(w2,ri);
		printf("%d\n",n+1+w1+w2);
	}
}