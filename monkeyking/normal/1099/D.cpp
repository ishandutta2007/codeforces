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
int n;
vector <int> vec[100005];
ll a[100005];
ll res=0;
bool haveres=true;

void dfs(int x,int depth,ll sum)
{
	if(!(depth&1))
	{
		if(sum>a[x])
		{
			haveres=false;
			return;
		}
		res+=a[x]-sum;
		for(int i=0;i<vec[x].size();i++)
		{
			dfs(vec[x][i],depth+1,a[x]);
		}
	}
	else
	{
		ll minx=1LL*inf*inf;
		for(int i=0;i<vec[x].size();i++)
		{
//			minx=min(minx,a[vec[x][i]]);
			if(a[vec[x][i]]-sum<0)
			{
				haveres=false;
				return;
			}
			minx=min(minx,a[vec[x][i]]-sum);
		}
		if(vec[x].size()==0)
		{
			return;
		}
		res+=minx;
		for(int i=0;i<vec[x].size();i++)
		{
			dfs(vec[x][i],depth+1,sum+minx);
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int x;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		x--;
		vec[x].push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",a+i);
	}
	dfs(0,0,0);
	if(haveres)
	{
		cout<<res<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}