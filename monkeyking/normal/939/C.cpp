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
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
ll n;
ll a[100005];
ll sum[100005];
ll s,f;

ll cal(ll l,ll r)
{
	while(l<=0) l+=n;
	while(r<=0) r+=n;
	if(l==r) return 0;
	if(l<r)
	{
		return sum[r]-sum[l];
	}
	else
	{
		return sum[n]-sum[l]+sum[r];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	rep(n)
	{
		scanf("%I64d",a+i+1);
	}
	sum[0]=0;
	for(ll i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	cin>>s>>f;
	ll mx=cal(s-1,f-1);
	ll k=1;
	for(ll i=2;i<=n;i++)
	{
		ll t=cal(s-i,f-i);
		if(t>mx)
		{
			mx=t;
			k=i;
		}
	}
	cout<<k<<endl;
	return 0;
}