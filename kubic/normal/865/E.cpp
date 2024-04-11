#include <bits/stdc++.h>
using namespace std;
#define N 25
#define M 1<<14
#define ll long long
const ll INF=1e18;
int n,s,a[N],b[N],w[M];ll ans=INF,pw[N],dp[M];char a1[N];
void print1(int x) {putchar(x<10?x+48:x+87);}
void print(ll x,int d)
{if(!d) return;print(x/16,d-1);print1(x%16);}
ll slv()
{
	for(int i=0;i<n;++i) if(b[i]<-15 || b[i]>15) return INF;
	s=0;for(int i=0;i<n;++i) s+=b[i];if(s) return INF;
	for(int i=1;i<1<<n;++i)
	{
		w[i]=w[i&i-1]+b[__builtin_ctz(i)];dp[i]=INF;
		if(w[i]<0 || w[i]>15) continue;
		for(int j=0;j<n;++j) if(i>>j&1 && dp[i^(1<<j)]<INF)
			dp[i]=min(dp[i],dp[i^(1<<j)]+w[i^(1<<j)]*pw[j]);
	}return dp[(1<<n)-1];
}
int main()
{
	scanf("%s",a1);n=strlen(a1);reverse(a1,a1+n);
	pw[0]=1;for(int i=1;i<n;++i) pw[i]=pw[i-1]*16;
	for(int i=0;i<n;++i) a[i]=isdigit(a1[i])?a1[i]-48:a1[i]-87;
	for(int i=0;i<1<<n-1;++i)
	{
		for(int j=0;j<n;++j) {b[j]=a[j];if(i>>j&1) b[j]-=16;}
		for(int j=0;j<n;++j) if(i>>j&1) ++b[j+1];ans=min(ans,slv());
	}if(ans<INF) print(ans,n);else printf("NO\n");return 0;
}