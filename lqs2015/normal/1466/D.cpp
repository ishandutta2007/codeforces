#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,w[111111],deg[111111],x,y,pos,id,cnt;
vector<int> g[111111];
pair<int,int> arr[222222];
long long ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&w[i]);
		ans=0;
		for (int i=1;i<=n;i++) ans+=w[i];
		for (int i=1;i<=n;i++) deg[i]=0;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			deg[x]++;deg[y]++;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cnt=0;
		for (int i=1;i<=n;i++) 
		{
			for (int j=1;j<deg[i];j++) arr[++cnt]=make_pair(w[i],i);
		}
		sort(arr+1,arr+cnt+1);reverse(arr+1,arr+cnt+1);
		pos=1;
		for (int i=1;i<n;i++)
		{
			printf("%lld ",ans);
			ans+=arr[pos].first;pos++;
		}
		printf("\n");
	}
	return Accepted;
}