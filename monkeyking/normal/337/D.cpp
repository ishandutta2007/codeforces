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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
int n,m,d;
int dist[2][100005];
vector <int> vec[100005];
bool evil[100005];

void dfs(int x,int p,int id,int now)
{
	dist[id][x]=now;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		dfs(vec[x][i],x,id,now+1);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>d;
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		evil[--x]=true;
	}
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		vec[--x].push_back(--y);
		vec[y].push_back(x);
	}
	dfs(0,-1,0,0);
	int maxn=0,a=-1;
	for(int i=0;i<n;i++)
	{
		if(evil[i] && maxn<dist[0][i]) maxn=dist[0][i],a=i;
	}
	dfs(a,-1,0,0);
	int b=0;
	maxn=-1;
	for(int i=0;i<n;i++)
	{
		if(evil[i] && maxn<dist[0][i]) maxn=dist[0][i],b=i;
	}
	dfs(b,-1,1,0);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(dist[0][i]<=d && dist[1][i]<=d) ans++;
	}
	cout<<ans<<endl;
	return 0;
}