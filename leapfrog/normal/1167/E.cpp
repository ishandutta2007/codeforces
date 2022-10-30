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
int n,m,fs[1000005],ls[1000005],pr[1000005];
int main()
{
	read(n),read(m);for(int i=1,x;i<=n;i++)
		{read(x),ls[x]=i,pr[i]=max(pr[i-1],x);if(!fs[x]) fs[x]=i;}
	int sf=m+1,wh=n+1;for(int i=m;i;i--)
		if(!fs[i]) sf=i;else if(ls[i]>wh) break;else sf=i,wh=fs[i];
	ll rs=0;int it=0;for(int l=1;l<=m;l++)
	{
		int r=max(sf-1,l);r=max(r,pr[it]),rs+=m-r+1;
		if(fs[l]&&fs[l]<it) break;else if(fs[l]) it=ls[l];
	}
	return printf("%lld\n",rs),0;
}