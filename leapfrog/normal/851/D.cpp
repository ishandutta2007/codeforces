//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=500005,V=2000005;
int n,X,Y,s[V],mx;ll sm[V];
int main()
{
	read(n,X,Y);for(int i=1,x;i<=n;i++) read(x),s[x]++,sm[x]+=x,mx=max(mx,x);
	for(int i=1;i<V;i++) sm[i]+=sm[i-1],s[i]+=s[i-1];
	int val=X/Y;ll rs=1e18;
	for(int i=2;i<=mx+1;i++)
	{
		ll sum=0;int qwq=min(val,i-1);
		for(int l=1,r=l+i-1;l<=mx;l+=i,r+=i)
			sum+=(s[r-qwq-1]-(l?s[l-1]:0))*1ll*X+(1ll*(s[r]-s[r-qwq-1])*r-sm[r]+sm[r-qwq-1])*Y;
		rs=min(rs,sum);
	}return printf("%lld\n",rs),0;
}