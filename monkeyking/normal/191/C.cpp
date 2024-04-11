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
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
vector <pii> vec[100005];
int x,y;
int q;
int depth[100005];
int par[18][100005];
int sum[100005];
int res[100005];

void magic(int x,int p,int d)
{
	depth[x]=d;
	par[0][x]=p;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i].first==p) continue;
		magic(vec[x][i].first,x,d+1);
	}
}

void init()
{
	memset(par,-1,sizeof(par));
	par[0][0]=-1;
	magic(0,0,0);
	for(int k=0;k<17;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(par[k][i]==-1)
			{
				par[k+1][i]=-1;
			}
			else
			{
				par[k+1][i]=par[k][par[k][i]];
			}
		}
	}
}

int lca(int a,int b)
{
	if(depth[a]<depth[b]) swap(a,b);
	int t=depth[a]-depth[b];
	for(int i=0;i<18;i++)
	{
		if((t & (1<<i))) a=par[i][a];
	}
	if(a==b) return a;
	for(int i=17;i>=0;i--)
	{
		if(par[i][a]!=par[i][b])
		{
			a=par[i][a];
			b=par[i][b];
		}
	}
	return par[0][a];
}

int dfs(int x,int p)
{
	int ans=sum[x];
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i].first==p) continue;
		res[vec[x][i].second]=dfs(vec[x][i].first,x);
		ans+=res[vec[x][i].second];
	}
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(mp(y,i));
		vec[y].push_back(mp(x,i));
	}
	init();
	cin>>q;
	int x,y;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		int z=lca(x,y);
//		cout<<z<<endl;
		sum[x]++;
		sum[y]++;
		sum[z]-=2;
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<sum[i]<<' ';
//	}
//	cout<<endl;
	dfs(0,-1);
	for(int i=0;i<n-1;i++)
	{
		cout<<res[i]<<' ';
	}
	cout<<endl;
	return 0;
}