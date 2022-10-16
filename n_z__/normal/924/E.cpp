#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v,tp;
}a[10001];
bool cmp(node a,node b)
{
	return !(a.tp>=b.tp&&(a.tp!=b.tp||a.v<=b.v));
}
int main()
{
	int n,l,r;
    cin>>n>>l>>r;
	int sum=0;
    for(int x=1;x<=n;x++)
	cin>>a[x].v,sum+=a[x].v;
    for(int x=1;x<=n;x++)
	cin>>a[x].tp;
    sort(a+1,a+n+1,cmp);
    int tmp=l;
	l=sum-r;
	r=sum-tmp;
	int dp[sum+1];
	for(int x=1;x<=sum;x++)
	dp[x]=-500000000;
    dp[0]=0;
    int ans=0;
    for(int x=1;x<=n;x++)
    for(int y=sum;y>=a[x].v;--y)
    dp[y]=max(dp[y],dp[y-a[x].v]+a[x].tp*(l<=y&&y<=r)),ans=max(ans,dp[y]);
    cout<<ans<<endl;
}