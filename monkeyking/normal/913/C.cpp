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
int n,x;
ll v[35],cost[35];
ll best=1000000000000000100;

bool compare(pair<ll,ll> a,pair<ll,ll> b)
{
	return a.first*v[b.second]<b.first*v[a.second];
}

ll up(ll a,ll b)
{
	return ((a+b-1)/b);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>cost[i];
	}
	for(int i=0;i<n;i++)
	{
		v[i]=(1LL<<(i));
	}
	ll t[35];
	pair<ll,ll> p[35];
	for(int i=0;i<n;i++)
	{
		p[i]=mp(cost[i],i);
	}
	ll ans=1000000000000000100LL;
	ll now=0;
	sort(p,p+n,compare);
//	for(int i=0;i<n;i++)
//	{
//		cout<<p[i].second+1<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		ll t=(x/v[p[i].second]);
//		cout<<t<<endl;
		if(x%v[p[i].second]!=0)
		{
			ans=min(ans,up(x,v[p[i].second])*cost[p[i].second]+now);
		}
		else
		{
			ans=min(ans,(x/v[p[i].second])*cost[p[i].second]+now);
			break;
		}
		now+=(t*cost[p[i].second]);
//		cout<<now<<endl;
		x=x%v[p[i].second];
//		cout<<ans<<Endl;
	}
	cout<<ans<<endl;
	return 0;
}