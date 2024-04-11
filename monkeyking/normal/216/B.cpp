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
int s1,s2;
bool visit[105];
int cry;
vector <int> vec[105];

void dfs(int x)
{
	visit[x]=true;
	s1++;
	s2+=vec[x].size();
	rep(vec[x].size())
	{
		if(visit[vec[x][i]]) continue;
		dfs(vec[x][i]);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int x,y;
	rep(m)
	{
		cin>>x>>y;
		vec[--x].push_back(--y);
		vec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		if(visit[i]) continue;
		s1=0;
		s2=0;
		dfs(i);
		if(s1%2==1 && s2==s1*2) cry++;
	}
	cout<<(cry+(n-cry)%2)<<endl;
	return 0;
}