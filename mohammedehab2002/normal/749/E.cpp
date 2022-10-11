#include <iostream>
#include <string.h>
using namespace std;
int n,arr[100005];
long long tree[100005];
void update(int idx,int val)
{
	while (idx<=n)
	{
		tree[idx]+=val;
		idx+=(idx&(-idx));
	}
}
long long query(int idx)
{
	long long ans=0;
	while (idx)
	{
		ans+=tree[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
double dp[100005];
int main()
{
	scanf("%d",&n);
	double ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		arr[i]=n-arr[i]+1;
		ans+=query(arr[i]);
		update(arr[i],1);
	}
	dp[1]=0;
	for (long long i=2;i<=n;i++)
	dp[i]=dp[i-1]+(double)(i-1)/2.0;
	double tmp=0;
	for (int i=1;i<=n;i++)
	tmp+=dp[i]*(n-i+1);
	memset(tree,0,sizeof(tree));
	for (int i=1;i<=n;i++)
	{
		tmp-=query(arr[i])*(n-i+1);
		update(arr[i],i);
	}
	tmp*=2.0;
	tmp/=(double)n*(n+1);
	printf("%.12lf",ans+tmp);
}