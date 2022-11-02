#include<bits/stdc++.h>
using namespace std;
int n,a[100005],k;long long dp[100005][15];
struct bit
{
	long long T[100005];
	inline void add(int x,long long y) {for(;x<=n;x+=x&(-x)) T[x]+=y;}
	inline long long qry(int x) {long long r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
}T[15];
int main()
{
	scanf("%d%d",&n,&k),++k;if(k==1) return printf("%d\n",n),0;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) {T[1].add(a[i],1);for(int j=2;j<=k&&j<=i;j++) dp[i][j]=T[j-1].qry(a[i]-1),T[j].add(a[i],dp[i][j]);}
	//for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) printf("%lld%c",dp[i][j],j==k?'\n':' ');
	long long r=0;for(int i=1;i<=n;i++) r+=dp[i][k];
	return printf("%lld\n",r),0;
}