#include<bits/stdc++.h>
using namespace std;
struct node{int a,b;}a1[105],a2[105];
int n,r,dp[100005],c1,c2,ans=0;
inline char cp1(node a,node b) {return a.a==b.a?a.b>b.b:a.a<b.a;}
inline char cp2(node a,node b) {return a.a+a.b==b.a+b.b?a.b>b.b:a.a+a.b>b.a+b.b;}
int main()
{
	scanf("%d%d",&n,&r),c1=c2=0;
	for(int i=1,a,b;i<=n;i++) scanf("%d%d",&a,&b),b>=0?(a1[++c1]=(node){a,b}):(a2[++c2]=(node){a,b});
	sort(a1+1,a1+c1+1,cp1),sort(a2+1,a2+c2+1,cp2),memset(dp,-1,sizeof(dp)),dp[r]=0;
	for(int i=1;i<=c1;i++) for(int j=60000;j>=a1[i].a;j--) if(~dp[j]) dp[j+a1[i].b]=max(dp[j]+1,dp[j+a1[i].b]);
	for(int i=1;i<=c2;i++) for(int j=a2[i].a;j<=60000;j++) if(~dp[j]&&j+a2[i].b>=0) dp[j+a2[i].b]=max(dp[j]+1,dp[j+a2[i].b]);
	for(int i=0;i<=60000;i++) ans=max(ans,dp[i]);
	return ans==n?puts("YES"):puts("NO"),0;
}