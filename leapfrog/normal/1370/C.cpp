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
int T,n,dp[1000005];
inline char dfs(int x)
{
	if(dp[x]!=-1) return dp[x];else if(x==1) return 0;
	for(int i=2;i<=x;i++) if((i&1)&&!(x%i)&&!dfs(x/i)) return dp[x]=1;
	return dp[x]=!dfs(x-1);
}
inline char chpr(int x)
{
	if(x==1) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main()
{
	// memset(dp,-1,sizeof(dp));
	// for(int i=1;i<=1000;i++) if(!dfs(i)) printf("%d\n",i);
	// for(int i=1;i<=1000;i++) if(dfs(i)^!((i&(-i))==i||(i%2==0&&chpr(i/2)))) printf("zcy ak %d\n",i);
	for(read(T);T--;) {read(n);if(n==2) puts("Ashishgup");else if((n&(-n))==n||(n%2==0&&chpr(n/2))) puts("FastestFinger");else puts("Ashishgup");}
	return 0;
}