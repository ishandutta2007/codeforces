//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
int n,v[300005],mb[300005];ll sm,a[300005],rs;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(v[i]),read(a[i]),sm+=v[i];
	if(sm<0) for(int i=1;i<=n;i++) v[i]=-v[i];
	for(int i=1;i<=n;i++) for(ll x=a[i];x;x>>=1) mb[i]++;
	for(int i=0;i<63;i++)
	{
		ll sm=0;for(int j=1;j<=n;j++) if(mb[j]==i+1) sm+=v[j];
		if(sm>0) {rs|=1ll<<i;for(int j=1;j<=n;j++) if((a[j]>>i)&1) v[j]=-v[j];}
	}
	return printf("%lld\n",rs),0;
}