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
ll n,m,w;
ll a[100005];
ll t[100005];
ll sum[100005];

bool check(ll h)
{
	for(ll i=0;i<n;i++)
	{
		t[i]=h-a[i];
		sum[i]=0;
	}
	ll r;
	for(ll i=0;i<n;i++)
	{
		r=(i-1<0?0:sum[i-1])-(i-w<0?0:sum[i-w]);
//		cout<<r<<' ';
		t[i]-=r;
		t[i]=max(0LL,t[i]);
		sum[i]=(i-1<0?t[i]:t[i]+sum[i-1]);
//		cout<<sum[i]<<' ';
	}
	return sum[n-1]<=m;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>w;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll l=0,r=10000000000000,tt;
//	cout<<check(3);
	ll ans;
//	return 0;
	while(l<=r)
	{
		tt=(l+r)/2;
		if(check(tt))
		{
			l=tt+1;
			ans=tt;
		}
		else
		{
			r=tt-1;
		}
	}
	cout<<ans<<Endl;
	return 0;
}