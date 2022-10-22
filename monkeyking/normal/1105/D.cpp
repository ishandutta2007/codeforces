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
#include <windows.h>
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
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
using namespace std;
int n,m,p;
int sp[18];
char c[1005][1005];
bool visit[1005][1005];
queue <pair<pair<int,int>,int> > que[18];
vector <pair<int,int> > vec[18];
bool ps[18];
int res[18];

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}

int bfs(int x)
{
//	cout<<x<<endl;
	int s=0;
	while(!que[x].empty()) que[x].pop();
	for(int i=0;i<vec[x].size();i++)
	{
//		cout<<vec[x][i].first<<' '<<vec[x][i].second<<endl;
		que[x].push(mp(vec[x][i],sp[x]));
	}
	vec[x].clear();
	while(que[x].size())
	{
		int nx=que[x].front().first.first;
		int ny=que[x].front().first.second;
		int ns=que[x].front().second;
		que[x].pop();
		if(ns==0)
		{
			vec[x].push_back(mp(nx,ny));
			continue;
		}
		for(int i=0;i<4;i++)
		{
			if(out(nx+dx[i],ny+dy[i])) continue;
			if(visit[nx+dx[i]][ny+dy[i]]) continue;
			visit[nx+dx[i]][ny+dy[i]]=true;
//			cout<<nx+dx[i]<<' '<<ny+dy[i]<<endl;
			que[x].push(mp(mp(nx+dx[i],ny+dy[i]),ns-1));
			s++;
		}
	}
//	cout<<x<<' '<<s<<endl;
	return s;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>p;
	for(int i=0;i<p;i++)
	{
		cin>>sp[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(isdigit(c[i][j]))
			{
				c[i][j]--;
				vec[c[i][j]-'0'].push_back(mp(i,j));
				res[c[i][j]-'0']++;
				visit[i][j]=true;
			}
			if(c[i][j]=='#')
			{
				visit[i][j]=true;
			}
		}
	}
	for(int i=0;i<p;i++)
	{
		ps[i]=true;
	}
//	bfs(0);
//	bfs(0);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<visit[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	cout<<vec[1].first<<' '<<vec[1].second<<endl;
	while(true)
	{
		bool flag=false;
		for(int i=0;i<p;i++)
		{
			if(!ps[i]) continue;
			int t=bfs(i);
			if(t==0) ps[i]=false;
			flag|=ps[i];
			res[i]+=t;
		}
		if(flag==false) break;
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//			{
//				cout<<visit[i][j]<<' ';
//			}
//			cout<<endl;
//		}
//		Sleep(1000);
	}
	for(int i=0;i<p;i++)
	{
		cout<<res[i]<<' ';
	}
	cout<<endl;
	return 0;
}