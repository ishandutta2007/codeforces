#include<bits/stdc++.h>
using namespace std;
int n,k,len[3333];
vector<int> arr[3333];
vector<long long> pre[3333];
long long cur[3333],ans,nw[22][3333];
void solve(int l,int r,int dep)
{
	if (l==r)
	{
		for (int i=0;i<=len[l] && i<=k;i++) ans=max(ans,pre[l][i]+cur[k-i]);
		return;
	}
	int mid=(l+r)>>1;
	for (int i=0;i<=k;i++) nw[dep][i]=cur[i];
	for (int i=mid+1;i<=r;i++)
	{
		for (int j=k;j>=len[i];j--) cur[j]=max(cur[j],cur[j-len[i]]+pre[i][len[i]]);
	}
	solve(l,mid,dep+1);
	for (int i=0;i<=k;i++) cur[i]=nw[dep][i];
	for (int i=l;i<=mid;i++)
	{
		for (int j=k;j>=len[i];j--) cur[j]=max(cur[j],cur[j-len[i]]+pre[i][len[i]]);
	}
	solve(mid+1,r,dep+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);arr[i].resize(len[i]+1);pre[i].resize(len[i]+1);
		for (int j=1;j<=len[i];j++) scanf("%d",&arr[i][j]);
		for (int j=1;j<=len[i];j++) pre[i][j]=pre[i][j-1]+arr[i][j];
	}
	solve(1,n,0);
	printf("%lld\n",ans);
	return 0;
}