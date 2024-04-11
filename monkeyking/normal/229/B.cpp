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
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
vector <pii> vec[100005];
vector <int> t[100005];
bool visit[100005];
ll dist[100005];
set <pair<ll,int> >squ;

ll cal(ll s,int nx)
{
	ll res=s;
	for(int i=lower_bound(t[nx].begin(),t[nx].end(),s)-t[nx].begin();i<t[nx].size();i++)
	{
		if(res==t[nx][i]) res++;
	}
//	if(nx==3) cout<<s<<' '<<res<<endl;
//	cout<<s<<' '<<nx<<' '<<res<<endl;
	return res;
}

int main()
{	
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		vec[x].push_back(mp(y,z));
		vec[y].push_back(mp(x,z));
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d",&y);
			t[i].push_back(y);
		}
	}
	memset(dist,0x3f,sizeof(dist));
	squ.insert(mp(0,0));
//	visit[0]=true;
	dist[0]=0;
	while(squ.size())
	{
		int x=squ.begin()->second;
		ll s=squ.begin()->first;
		squ.erase(mp(s,x));
//		cout<<x<<' '<<s<<endl;
		if(visit[x]) continue;
		visit[x]=true;
		s=cal(s,x);
		for(int i=0;i<vec[x].size();i++)
		{
			int nx=vec[x][i].first;
			int d=vec[x][i].second+s;
//			cout<<nx<<' '<<d<<endl;
//			if(x==1) cout<<nx<<endl;
//			cout<<nx<<endl;
			if(d<dist[nx])
			{
				dist[nx]=d;
//				visit[nx]=true;
				squ.insert(mp(dist[nx],nx));
			}
		}
	}
//	cout<<dist[0]<<' '<<dist[1]<<' '<<dist[2]<<' '<<dist[3]<<endl;
	if(!visit[n-1]) over("-1") else cout<<dist[n-1]<<endl;
	return 0;
}