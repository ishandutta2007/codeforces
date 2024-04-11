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
int a[200005];
vector <int> vec[200005];
int res;
int bp[200005];
bool visit[200005];
bool isprime[200005];
vector <int> prime;

int dfs(int x,int p,int k)
{
//	cout<<x<<' '<<p<<' '<<k<<endl;
	int m1=0,m2=0;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		int t=dfs(vec[x][i],x,k);
		if(t>m1)
		{
			m2=m1;
			m1=t;
		}
		else if(t>m2)
		{
			m2=t;
		}
	}
	if(a[x]%k==0)
	{
		res=max(res,m1+m2+1);
		return m1+1;
	}
	else
	{
		res=max(res,m1);
		return 0;
	}
}

int go(int x,int p,int k)
{
//	cout<<x<<' '<<p<<' '<<k<<endl;
	int m1=0,m2=0;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		if(visit[vec[x][i]]) continue;
		visit[vec[x][i]]=true;
		int t=go(vec[x][i],x,k);
		if(t>m1)
		{
			m2=m1;
			m1=t;
		}
		else if(t>m2)
		{
			m2=t;
		}
	}
	if(a[x]%k==0)
	{
		res=max(res,m1+m2+1);
		return m1+1;
	}
	else
	{
		res=max(res,m1);
		return 0;
	}
}

int main()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=200000;i++)
	{
		if(isprime[i]) prime.push_back(i);
		for(int j=0;j<prime.size();j++)
		{
			if(prime[j]*i>200000) break;
			isprime[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=0;prime[i]*prime[i]<=200000;i++)
	{
		dfs(0,-1,prime[i]);
	}
	for(int i=0;i<n;i++)
	{
		int tx=a[i];
		for(int j=0;prime[j]*prime[j]<=200000;j++)
		{
			while(tx%prime[j]==0)
			{
				tx/=prime[j];
			}
		}
		bp[i]=tx;
	}
	for(int i=0;i<n;i++)
	{
		if(!visit[i] && bp[i]!=1) visit[i]=true,res=max(res,go(i,-1,bp[i]));
	}
	cout<<res<<endl;
	return 0;
}