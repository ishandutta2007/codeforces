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
int n,m;
vector <int> vec[500];
bool visit[500];

void dfs(int x)
{
	visit[x]=true;
	for(int i=0;i<vec[x].size();i++)
	{
		if(visit[vec[x][i]]) continue;
		dfs(vec[x][i]);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int t[105],x;
	bool f=false;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		f|=x;
		for(int j=0;j<x;j++)
		{
			cin>>t[j];
			vec[i+200].push_back(--t[j]);
//			cout<<t[j]<<endl;
			vec[t[j]].push_back(i+200);
		}
	}
	int ans=-1;
//	for(int i=0;i<m;i++)
//	{
//		if(!visit[i])
//		{
//			dfs(i);
//			ans++;
//		}
//	}
//	cout<<ans<<endl;
	for(int i=200;i<n+200;i++)
	{
		if(!visit[i])
		{
			dfs(i);
			ans++;
		}
	}
	cout<<ans+!f<<endl;
	return 0;
}