//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,d[100005],st[100005],tp,c[100005],b[100005],tt;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(d[i]);
	for(int i=1;i<=n;i++)
	{
		while(tp&&st[tp]-d[st[tp]]>=i-d[i]) tp--;
		st[++tp]=i;
	}
	while(tp) b[++tt]=st[tp--],c[tt]=b[tt]-d[b[tt]]-1;
	//for(int i=1;i<=tt;i++) printf("%d%c",b[i],i==tt?'\n':' ');
	int nw=tt,m=0;ll ans=0;for(int i=1;i<=n;i++)
	{
		if(nw>1&&i>b[nw]) nw--;
		if(i-m>c[nw]) m++;
		ans+=(m-d[i]-1);
	}
	return printf("%lld\n",ans),0;
}