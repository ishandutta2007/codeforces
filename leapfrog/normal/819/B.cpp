//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,c[2000005],p[2000005];long long cz,sz,cf,sf;
int main()
{
	read(n),cz=sz=cf=sf=0;
	for(int i=1;i<=n;i++) read(p[i]);
	for(int i=1;i<=n;i++) if(p[i]-i<=0) ++cf,sf+=i-p[i];else ++c[p[i]-i],++cz,sz+=p[i]-i;
	long long ans=sz+sf;int nw=0;
	for(int i=1;i<=n;i++)
	{
		sz-=cz,cz-=c[i],sf+=cf,cf+=c[i];long long qwq=p[n-i+1];
		sf-=n-qwq+1,--cf;if(qwq>1) ++c[qwq+i-1],sz+=qwq-1,++cz;else ++cf;
		if(ans>sz+sf) ans=sz+sf,nw=i;
	}
	return printf("%lld %d\n",ans,nw),0;
}