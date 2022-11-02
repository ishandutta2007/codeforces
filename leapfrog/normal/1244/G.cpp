//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,p[1000005];ll K,vl;
int main()
{
	read(n),read(K);if(K<1ll*n*(n+1)/2) return puts("-1"),0;
	K-=1ll*n*(n+1)/2;for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1,r=n;i<=r;i++,r--)
	{
		int dl=r-i;if(K>dl) swap(p[i],p[r]),K-=dl;
		else {swap(p[i],p[i+K]);break;}
	}
	for(int i=1;i<=n;i++) vl+=max(p[i],i);
	printf("%lld\n",vl);for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');
	for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
	return 0;
}