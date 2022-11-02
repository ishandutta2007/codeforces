//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int Ca,n,a[200005],K,p[2000005],pc,ls[10000005],ps[10000005],dp[200005];char v[10000005];
inline void init()
{
	const int N=1e7;v[1]=ls[1]=1;for(int i=1;i<=N;i++)
	{
		if(!v[i]) p[++pc]=i,ls[i]=i;
		for(int j=1;j<=pc&&i*p[j]<=N;j++) {v[i*p[j]]=1,ls[i*p[j]]=p[j];if(i%p[j]==0) break;}
	}
}
inline int work(int w)
{
	int r=1;while(w^1)
		if(ls[w]^ls[w/ls[w]]) r*=ls[w],w/=ls[w];
		else w/=ls[w],w/=ls[w];
	return r;
}
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]),a[i]=work(a[i]);
	for(int i=1;i<=n;i++) dp[i]=max(dp[ps[a[i]]]+1,dp[i-1]),ps[a[i]]=i;
	printf("%d\n",dp[n]);for(int i=1;i<=n;i++) ps[a[i]]=0;
}
int main() {for(init(),read(Ca);Ca--;) solve();return 0;}