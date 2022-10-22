#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
int n;
vector <int> vec[100005];
int a[100005];
int par[100005];
ll dp[100005][2];

void ff(int x,int p)
{
	par[x]=p;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		ff(vec[x][i],x);
	}
}

ll dfs(int x,int k)
{
	if(dp[x][k]!=-1) return dp[x][k];
	ll neg=0,pos=0;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==par[x]) continue;
		neg=max(neg,dfs(vec[x][i],0));
		pos=max(pos,dfs(vec[x][i],1));
	}
	a[x]-=neg;
	a[x]+=pos;
	if(a[x]<0) pos-=a[x];else neg+=a[x];
	dp[x][0]=neg;
	dp[x][1]=pos;
	return dp[x][k];
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	ff(0,-1);
	cout<<dfs(0,0)+dfs(0,1)<<endl;
	return 0;
}