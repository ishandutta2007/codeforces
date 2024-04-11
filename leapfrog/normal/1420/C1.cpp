//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,Q,a[300005];long long sm=0;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(Q),a[0]=a[n+1]=sm=0;
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) sm+=max(a[i]-a[i+1],0);
		printf("%lld\n",sm);while(Q--)
		{
			int l,r;read(l),read(r);
			sm-=max(a[l]-a[l-1],0),sm-=max(a[l+1]-a[l],0);
			sm-=(l+1!=r?max(a[r]-a[r-1],0):0),sm-=max(a[r+1]-a[r],0);
			swap(a[l],a[r]);
			sm+=max(a[l]-a[l-1],0),sm+=max(a[l+1]-a[l],0);
			sm+=(l+1!=r?max(a[r]-a[r-1],0):0),sm+=max(a[r+1]-a[r],0);
			printf("%lld\n",sm);
		}
	}
	return 0;
}