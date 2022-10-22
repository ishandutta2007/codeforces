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
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int dp[105][105][27][2];
int n,m;
vector <pair<int,int> >vec[105];

bool dfs(int x,int y,int k,bool turn)
{
//	cout<<x<<' '<<y<<' '<<(char)(k+'a')<<' '<<turn<<endl;
	if(dp[x][y][k][turn]!=-1) return dp[x][y][k][turn];
	dp[x][y][k][turn]=false;
	if(turn==0)
	{
		for(int i=0;i<vec[x].size();i++)
		{
			if(vec[x][i].second<k) continue;
			dp[x][y][k][turn]|=(!dfs(vec[x][i].first,y,vec[x][i].second,1));
		}
	}
	else
	{
		for(int i=0;i<vec[y].size();i++)
		{
			if(vec[y][i].second<k) continue;
			dp[x][y][k][turn]|=(!dfs(x,vec[y][i].first,vec[y][i].second,0));
		}
	}
	return dp[x][y][k][turn];
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int x,y;
	char c;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		c=' ';
		while(!isalpha(c)) c=getchar();
		c-='a';
		x--;
		y--;
		vec[x].push_back(mp(y,c));
//		vec[y].push_back(mp(x,c));
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<(dfs(i,j,0,0)?'A':'B');
		}
		cout<<endl;
	}
	return 0;
}