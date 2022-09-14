#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
long long K;
int A[2<<17];
vector<int>G[2<<17];
long long dp[2<<17];
void dfs(int u,int LIM)
{
	dp[u]=-2;
	long long mx=0;
	for(int v:G[u])if(A[v]<=LIM)
	{
		if(dp[v]==-2)mx=K;
		else
		{
			if(dp[v]==-1)dfs(v,LIM);
			mx=max(mx,dp[v]+1);
		}
	}
	dp[u]=mx;
}
bool check(int LIM)
{
	for(int i=0;i<N;i++)dp[i]=-1;
	for(int i=0;i<N;i++)if(A[i]<=LIM&&dp[i]==-1)
	{
		dfs(i,LIM);
	}
	for(int i=0;i<N;i++)if(dp[i]>=K-1)return true;
	return false;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;u--,v--;
		G[u].push_back(v);
	}
	vector<int>a(A,A+N);
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int l=-1,r=a.size();
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(a[mid]))r=mid;
		else l=mid;
	}
	cout<<(r==a.size()?-1:a[r])<<endl;
}