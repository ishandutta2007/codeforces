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
int dp[50005][505];
int n,d;
vector <int> vec[50005];
int ans;

void dfs(int x,int p)
{
	dp[x][0]=1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		dfs(vec[x][i],x);
		for(int j=0;j<=d;j++)
		{
			ans+=dp[vec[x][i]][d-j-1]*dp[x][j];
			if(j>0) dp[x][j]+=dp[vec[x][i]][j-1];
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>d;
	int x,y;
	rep(n-1)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(0,-1);
	cout<<ans<<Endl;
	return 0;
}