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
const int mod=1e9+7;
using namespace std;
int n,m;
int cost[100005];
vector <int> vec[100005];
vector <int> rvec[100005];
bool visit[100005];
vector <int> order;
vector <int> v;

void dfs(int x)
{
	for(int i=0;i<vec[x].size();i++)
	{
		if(visit[vec[x][i]]) continue;
		visit[vec[x][i]]=true;
		dfs(vec[x][i]);
	}
	order.push_back(x);
}

void scc(int x)
{
	v.push_back(x);
	for(int i=0;i<rvec[x].size();i++)
	{
		if(visit[rvec[x][i]]) continue;
		visit[rvec[x][i]]=true;
		scc(rvec[x][i]);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",cost+i);
	}
	int x,y;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		rvec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		if(!visit[i])
		{
			visit[i]=true;
			dfs(i);
		}
	}
	memset(visit,0,sizeof(visit));
	ll res1=inf,res2=1,ans1=0,ans2=1;
	for(int i=n-1;i>=0;i--)
	{
		if(!visit[order[i]])
		{
			visit[order[i]]=true;
			v.clear();
			scc(order[i]);
//			cout<<v.size()<<':';
			res1=inf;
			res2=0;
			for(int j=0;j<v.size();j++)
			{
//				cout<<v[j]<<' ';
				if(cost[v[j]]<res1)
				{
					res1=cost[v[j]];
					res2=1;
				}
				else if(cost[v[j]]==res1)
				{
//					cout<<v[j]<<' ';
					res2++;
				}
//				ans2*=res2;
			}
			ans2*=res2;
			ans2%=mod;
//				cout<<res1<<endl;
			ans1+=res1;
//			cout<<endl;
		}
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}