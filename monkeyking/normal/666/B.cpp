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
const int inf=1003479213;
int n,m;
vector <int> vec[3005];
int dist[3005][3005];
pii from[3005][3],to[3005][3];

void bfs(int x)
{
	int cur=0;
	queue <pii> que;
	dist[x][x]=0;
	que.push(mp(x,0));
	while(que.size())
	{
		int nx=que.front().first;
		int ns=que.front().second+1;
		que.pop();
		for(int i=0;i<vec[nx].size();i++)
		{
			int v=vec[nx][i];
			if(dist[x][v]>ns)
			{
//				cout<<v<<' ';
				dist[x][v]=ns;
				que.push(mp(v,ns));
			}
		}
	}
//	cout<<endl;
}

void init()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			from[i][j].first=-inf;
			to[i][j].first=-inf;
			from[i][j].second=-1;
			to[i][j].second=-1;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	memset(dist,0x3f,sizeof(dist));
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		vec[--x].push_back(--y);
	}
	for(int i=0;i<n;i++)
	{
		bfs(i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
//			cout<<(dist[i][j]==1061109567?-inf:dist[i][j])<<' ';
			dist[i][j]=(dist[i][j]==1061109567?-inf:dist[i][j]);
		}
//		cout<<endl;
	}
//	return 0;
	init();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(from[i][0].first<dist[i][j])
			{
				from[i][2]=from[i][1];
				from[i][1]=from[i][0];
				from[i][0]=mp(dist[i][j],j);
			}
			else
			{
				if(from[i][1].first<dist[i][j])
				{
//					cout<<i<<' '<<j<<Endl;
					from[i][2]=from[i][1];
					from[i][1]=mp(dist[i][j],j);
				}
				else
				{
					if(from[i][2].first<dist[i][j]) from[i][2]=mp(dist[i][j],j);
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(to[i][0].first<dist[j][i])
			{
				to[i][2]=to[i][1];
				to[i][1]=to[i][0];
				to[i][0]=mp(dist[j][i],j);
			}
			else
			{
				if(to[i][1].first<dist[j][i])
				{
					to[i][2]=to[i][1];
					to[i][1]=mp(dist[j][i],j);
				}
				else
				{
					if(to[i][2].first<dist[j][i])
					{
						to[i][2]=mp(dist[j][i],j);
					}
				}
			}
		}
	}
//	cout<<"From:\n";
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			cout<<from[i][j].first<<'-'<<from[i][j].second+1<<"  ";
//		}
//		cout<<endl;
//	}
//	cout<<"\nTo:\n";
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			cout<<to[i][j].first<<'-'<<to[i][j].second+1<<"  ";
//		}
//		cout<<endl;
//	}
//	return 0;
//	cout<<dist[4][1]<<endl;
	int a,b,maxd=0,ma,mb,md=0;
	int road[4];
//	bool f=false;
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{
			if(j==k) continue;
			if(dist[j][k]==-inf) continue;
			maxd=-inf;
			for(int i=0;i<3;i++)
			{
				for(int l=0;l<3;l++)
				{
					a=to[j][i].second;
					b=from[k][l].second;
					if(a==-1) continue;
					if(b==-1) continue;
					if(a==b) continue;
					if(a==j) continue;
					if(a==k) continue;
					if(b==j) continue;
					if(b==k) continue;
//					cout<<"Go\n";
					if(to[j][i].first+from[k][l].first<maxd) continue;
					maxd=to[j][i].first+from[k][l].first;
					ma=a;
					mb=b;
				}
			}
			if(maxd+dist[j][k]<md) continue;
			md=dist[j][k]+maxd;
			road[0]=ma;
			road[1]=j;
			road[2]=k;
			road[3]=mb;
//			f=true;
		}
	}
//	cout<<dist[3][0]<<'\n';
//	if(f==false) cout<<"NO_CHANGE\n";
//	cout<<md<<endl;
//	cout<<dist[1][2]<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<road[i]+1<<' ';
	}
	cout<<endl;
	return 0;
}