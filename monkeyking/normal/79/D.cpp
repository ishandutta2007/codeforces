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
int n,k,l;
int p[15];
int a[105];
int dist[25][10005];
int s[25];
int dp[(1<<20)];
bool fuck[10005];

void bfs(int st)
{
//	if(st!=1) return;
//	memset(dist,0x3f,sizeof(dist));
	dist[st][s[st]]=0;
	queue <int> que;
	que.push(s[st]);
	while(que.size())
	{
		int x=que.front();
		que.pop();
		for(int i=0;i<l;i++)
		{
//			if(a[i]==5000 && x==5003) cout<<"FUCK";
			if(x-a[i]>=0 && dist[st][x-a[i]]>dist[st][x]+1)
			{
				dist[st][x-a[i]]=dist[st][x]+1;
				que.push(x-a[i]);
			}
			if(x+a[i]<=n && dist[st][x+a[i]]>dist[st][x]+1)
			{
//				if(x+a[i]==10000 && dist[st][x]==1) cout<<x<<' '<<a[i]<<endl;
				dist[st][x+a[i]]=dist[st][x]+1;
				que.push(x+a[i]);
			}
		}
	}
//	cout<<dist[1][9999]<<endl;
//	cout<<dist[1][3]<<endl;
//	for(int i=0;i<=n;i++)
//	{
//		cout<<dist[i]<<' ';
//	}
//	cout<<endl;
}

//void dfs(int x)
//{
//	for(int i=0;i<l;i++)
//	{
//		if(x-a[i]>=0 && !visit[x-a[i]])
//		{
//			visit[x-a[i]]=true;
//			dfs(x-a[i]);
//		}
//		if(x+a[i]<=n && !visit[x+a[i]])
//		{
//			visit[x+a[i]]=true;
//			dfs(x+a[i]);
//		}
//	}
//}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k>>l;
	for(int i=0;i<k;i++)
	{
		scanf("%d",p+i);
		p[i]--;
	}
	for(int i=0;i<l;i++)
	{
		scanf("%d",a+i);
	}
//	visit[0]=true;
//	dfs(0);
	vector <int> vec;
	for(int i=0;i<k;i++)
	{
		fuck[p[i]]^=1;
		fuck[p[i]+1]^=1;
	}
	k=0;
	for(int i=0;i<=n;i++)
	{
		if(fuck[i]) s[k++]=i;
//		s[k++]=vec[i];
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<k;i++)
	{
		bfs(i);
	}
//	cout<<"FUCK";
//	cout<<dist[10000]<<' '<<dist[9998]<<endl;
//	for(int i=0;i<k;i++)
//	{
//		cout<<s[i]<<'-';
//	}
//	cout<<endl;
//	cout<<dist[1][9999]<<endl;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int mask=0;mask<(1<<k);mask++)
	{
		int from;
		for(from=0;from<k;from++)
		{
			if(!((1<<from) & mask)) break;
		}
		for(int to=from+1;to<k;to++)
		{
			if((1<<to) & mask) continue;
			int d=abs(s[to]-s[from]);
//			cout<<s[to]<<' '<<s[from]<<endl;
			dp[mask|(1<<to)|(1<<from)]=min(dp[mask|(1<<to)|(1<<from)],dp[mask]+dist[from][s[to]]);
		}
	}
	cout<<(dp[(1<<k)-1]>inf?-1:dp[(1<<k)-1])<<endl;
	return 0;
}