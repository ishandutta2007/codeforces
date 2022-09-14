#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
long long mod=998244353;
int N,M;
vector<int>G[500];
int C[1<<20];
unordered_map<long long,int>dp;
int st[20][1<<20];
int lookup[1<<20];
int rmp(int L,int R)
{
	int b=lookup[R-L];
	return min(st[b][L],st[b][R-(1<<b)]);
}
int dfs(int L,int R)
{
	if(L==R)return 1;
	long long p=(long long)R*M+L;
	int c=rmp(L,R);
	if(G[c][0]<L||R<=G[c].back())return 0;
	else if(L+1>=R)return 1;
	else if(dp.find(p)!=dp.end())return dp[p];
	long long ret=1;
	for(int i=1;i<G[c].size();i++)
	{
		ret=ret*dfs(G[c][i-1]+1,G[c][i])%mod;
		if(ret==0)break;
	}
	if(ret!=0)
	{
		long long retL=0;
		for(int l=L;l<=G[c][0];l++)
		{
			retL=(retL+(long long)dfs(L,l)*dfs(l,G[c][0])%mod)%mod;
		}
		ret=ret*retL%mod;
	}
	if(ret!=0)
	{
		long long retR=0;
		for(int r=G[c].back()+1;r<=R;r++)
		{
			retR=(retR+(long long)dfs(G[c].back()+1,r)*dfs(r,R)%mod)%mod;
		}
		ret=ret*retR%mod;
	}
	dp[p]=(int)ret;
	return ret;
}
main()
{
	cin>>N>>M;
	int id=0;
	for(int i=0;i<M;i++)
	{
		cin>>C[id];
		C[id++]--;
		if(id>1&&C[id-2]==C[id-1])id--;
	}
	M=id;
	for(int i=0;i<M;i++)G[C[i]].push_back(i);
	for(int i=0;i<M;i++)st[0][i]=C[i];
	for(int i=1;i<20;i++)
	{
		for(int j=0;j+(1<<i)<=1<<20;j++)
		{
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
		}
	}
	for(int i=2;i<1<<20;i++)lookup[i]=lookup[i>>1]+1;
	for(int i=0;i<N;i++)
	{
		int L=G[i][0],R=G[i].back();
		if(rmp(L,R+1)!=i)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<dfs(0,M)<<endl;
}