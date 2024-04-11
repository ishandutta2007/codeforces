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
int cost[200005];
int nxt[200005];
int res=0;
vector <int> vec;
int visit[200005];
int k;

void dfs(int x)
{
	vec.push_back(x);
	visit[x]=1;
	if(visit[nxt[x]]==2)
	{
		visit[x]=2;
		return;
	}
	else if(visit[nxt[x]]==0)
	{
		dfs(nxt[x]);
	}
	else
	{
		k=nxt[x];
	}
	visit[x]=2;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",cost+i);
	}
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		x--;
		nxt[i]=x;
	}
	int minx;
	for(int i=0;i<n;i++)
	{
		if(visit[i]) continue;
//		cout<<i<<endl;
		k=-1;
		vec.clear();
		dfs(i);
		if(k==-1) continue;
		minx=inf;
		bool f=false;
		for(int j=0;j<vec.size();j++)
		{
//			cout<<vec[j]<<' ';
			if(vec[j]==k)
			{
				f=true;
			}
			if(f) minx=min(minx,cost[vec[j]]);
		}
//		cout<<endl;
//		cout<<minx<<endl;
		res+=minx;
	}
	cout<<res<<endl;
	return 0;
}