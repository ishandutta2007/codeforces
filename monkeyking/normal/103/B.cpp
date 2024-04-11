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
int n,m;
vector <int> vec[105];
bool visit[105];
int road[105];
int start=-1;
int f[105];
int use[105];
bool flag=false;
bool no[105];

void init()
{
	for(int i=0;i<105;i++)
	{
		f[i]=i;
	}
}

int find(int x)
{
	return (x==f[x]?x:f[x]=find(f[x]));
}

void add(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rand()&1) f[x]=y;else f[y]=x;
}

void dfs(int x,int p)
{
	use[x]=1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		if(use[vec[x][i]])
		{
			flag=true;
			for(int i=0;i<n;i++)
			{
//				cout<<use[i]<<' ';
				if(use[i]==1) no[i]=true;
			}
//			cout<<endl;
			return;
		}
		dfs(vec[x][i],x);
		if(flag) return;
	}
	use[x]=2;
}

void krk(int x,int p)
{
	visit[x]=true;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		if(visit[vec[x][i]]) over("NO");
		krk(vec[x][i],x);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	init();
	cin>>n>>m;
	int x,y;
	rep(m)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		add(x,y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<n;i++)
	{
		if(find(i)!=find(0)) over("NO");
	}
	dfs(0,-1);
	memset(visit,0,sizeof(visit));
	for(int i=0;i<n;i++)
	{
		if(no[i]) visit[i]=true;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(!no[i]) continue;
		res++;
		for(int j=0;j<vec[i].size();j++)
		{
			if(no[vec[i][j]]) continue;
			krk(vec[i][j],i);
		}
	}
	if(res<=2) over("NO");
	cout<<"FHTAGN!\n";
//	cout<<start<<endl;
	return 0;
}