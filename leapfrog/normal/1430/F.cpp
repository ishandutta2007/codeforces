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
int n;long long k,l[200005],r[200005],v[200005],dp[200005];
int main()
{
	read(n),read(k);for(int i=1;i<=n;i++) read(l[i]),read(r[i]),read(v[i]);
	for(int i=n;i;i--) dp[i]=max(v[i]+(i!=n&&l[i+1]==r[i]?dp[i+1]:0)-(r[i]-l[i])*k,0ll);
	for(int i=n;i;i--) if((r[i]-l[i]+1)*k<v[i]+(i!=n&&l[i+1]==r[i]?dp[i+1]:0)) return puts("-1"),0;
	long long rs=0,qwq=k;for(int i=1;i<=n;rs+=v[i],qwq=((qwq-v[i])%k+k)%k,i++) if(qwq<dp[i]) rs+=qwq,qwq=k;
	return printf("%lld\n",rs),0;
}