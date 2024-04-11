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
const int mod=1e9+7;
int n;
vector <ll> vec[100005];
bool a[100005];
ll dp[100005][2];

ll kuaism(ll n,ll m,ll mod)
{
	long long basic=n;
	long long ans=1;
	while(m)
	{
		if(m&1)
		{
			ans*=basic;
			ans%=mod;
		}
		m>>=1;
		basic=basic*basic;
		basic=basic%mod;
	}
	return (ll)ans;
}

ll dfs(ll x,bool c)
{
	if(dp[x][c]!=-1) return dp[x][c];
	if(vec[x].size()==0)
	{
		return dp[x][c]=(a[x]==c);
	}
	if(c==true && a[x]==false)
	{
		ll res=0;
		ll k=1;
		for(ll i=0;i<vec[x].size();i++)
		{
			k*=(dfs(vec[x][i],true)+dfs(vec[x][i],false)%mod)%mod;
			k%=mod;
		}
		ll t;
		for(ll i=0;i<vec[x].size();i++)
		{
			t=(dfs(vec[x][i],true)+dfs(vec[x][i],false));
			t%=mod;
			res+=((1LL*k*kuaism(t,1e9+5,mod))%mod*dfs(vec[x][i],true))%mod;
			res%=mod;
		}
		return dp[x][c]=res%mod;
	}
	else if(c==false &&  a[x]==false)
	{
		ll res=1;
		for(ll i=0;i<vec[x].size();i++)
		{
			res*=(dfs(vec[x][i],false)+dfs(vec[x][i],true))%mod;
			res%=mod;
		}
		return dp[x][c]=res%mod;
	}
	else if(a[x]==true && c==false)
	{
		return dp[x][c]=0;
	}
	else if(a[x]==true && c==true)
	{
		ll res=1;
		for(ll i=0;i<vec[x].size();i++)
		{
			res*=(dfs(vec[x][i],false)+dfs(vec[x][i],true))%mod;
			res%=mod;
		}
		return dp[x][c]=res%mod;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	ll t;
	for(ll i=1;i<n;i++)
	{
		scanf("%I64d",&t);
		vec[t].push_back(i);
	}
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&t);
		a[i]=t;
	}
	cout<<dfs(0,true)<<endl;
//	if(n==1000)
//	{
//		for(ll i=0;i<n;i++)
//		{
//			cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
//		}
//	}
	return 0;
}