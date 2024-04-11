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
typedef unsigned long long ull;
using namespace std;
vector <int> vec[1005];
int n;

int dfs(int x,int p)
{
	int ans=0;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		ans+=dfs(vec[x][i],x);
	}
	if(ans<3 && vec[x].size())
	{
		cout<<"No\n";
		exit(0);
	}
	if(ans==0) return 1;
	return 0;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int x;
	rep(n-1)
	{
		cin>>x;
		vec[--x].push_back(i+1);
	}
	dfs(0,-1);
	cout<<"Yes\n";
	return 0;
}