#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=998244353;
int N;
int X[100],Y[100];
vector<int>near[100];
int MD[100];
long long dp[2][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
	for(int i=0;i<N;i++)
	{
		int dm=1e9;
		for(int j=0;j<N;j++)if(i!=j)
		{
			int d=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
			if(dm>d)
			{
				dm=d;
				near[i].clear();
			}
			if(dm==d)near[i].push_back(j);
		}
		MD[i]=dm;
	}
	vector<int>Gs;
	int rest=N;
	for(int i=0;i<N;i++)
	{
		if(near[i][0]<i)continue;
		bool vis[100]={};
		bool ok=true;
		for(int v:near[i])
		{
			vis[v]=true;
			if(MD[v]!=MD[i])
			{
				ok=false;
				break;
			}
		}
		if(!ok)continue;
		vis[i]=true;
		for(int v:near[i])
		{
			bool all=true;
			for(int w:near[v])if(!vis[w])
			{
				all=false;
				break;
			}
			if(!all||near[i].size()!=near[v].size())
			{
				ok=false;
				break;
			}
		}
		if(!ok)continue;
		Gs.push_back(near[i].size()+1);
		rest-=Gs.back();
	}
	int now=0;
	dp[now][rest]=1;
	for(int u:Gs)
	{
	    int nxt=1-now;
	    for(int j=0;j<=N;j++)dp[nxt][j]=0;
		for(int j=0;j<N;j++)if(dp[now][j])
		{
			dp[nxt][j+u]+=dp[now][j];
			if(dp[nxt][j+u]>=mod)dp[nxt][j+u]-=mod;
			dp[nxt][j+1]+=dp[now][j];
			if(dp[nxt][j+1]>=mod)dp[nxt][j+1]-=mod;
		}
		now=nxt;
	}
	long long ans=0;
	long long perm=1;
	for(int j=1;j<=N;j++)
	{
		perm=perm*(N-j+1)%mod;
		ans+=dp[now][j]*perm%mod;
		if(ans>=mod)ans-=mod;
	}
	cout<<ans<<endl;
}