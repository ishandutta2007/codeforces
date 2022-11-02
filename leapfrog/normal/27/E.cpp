//
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,pc,p[1005];char v[1000005];ll dp[1005][1005];
inline ll ksm(ll x,int q) {ll r=1;for(;q;q>>=1,x*=x) if(q&1) r*=x;return r;}
inline ll dfs(int x,int cnt,int lst)
{
	if(x==1) return dp[x][cnt]=1;else if(dp[x][cnt]) return dp[x][cnt];else dp[x][cnt]=1e18+5;
	for(int i=2;i<=min(lst,i);i++) if(x%i==0&&pow(p[cnt],i-1)*dfs(x/i,cnt+1,i)<=1e18) dp[x][cnt]=min(dp[x][cnt],dfs(x/i,cnt+1,i)*ksm(p[cnt],i-1));
	return dp[x][cnt];
}
int main()
{
	read(n);
	for(int i=2;pc<=n;i++)
	{
		if(!v[i]) p[++pc]=i;
		for(int j=1;j<=pc&&p[j]*i<=1000000;j++) {v[i*p[j]]=1;if(i%p[j]==0) break;}
	}
// 	for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
	return printf("%lld\n",dfs(n,1,n)),0;
}