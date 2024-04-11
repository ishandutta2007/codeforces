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
const ll inf=103974999999990182;
using namespace std;
ll n,m;
const ll v=300;
ll b[400][v];
ll mb[400];
ll h[400];

ll query(ll x)
{
	ll l=0,r=x/v;
	ll m=0;
	for(int i=0;i<r;i++)
	{
		m=max(m,mb[i]);
	}
	for(int i=r*v;i<x;i++)
	{
//		cout<<i<<endl;
		m=max(m,max(b[i/v][i%v],h[i/v]));
	}
	return m;
}

void change(ll x,ll num)
{
	for(int i=0;i<x/v;i++)
	{
		mb[i/v]=num;
		h[i/v]=num;
	}
	for(int i=((ll)(x/v))*v;i<x;i++)
	{
		b[i/v][i%v]=num;
		mb[i/v]=max(mb[i/v],b[i/v][i%v]);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	m=n/v;
	ll x;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&x);
		b[i/v][i%v]=x;
	}
	for(int i=0;i<400;i++)
	{
		mb[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		mb[i/v]=max(mb[i/v],b[i/v][i%v]);
	}
	ll q;
	cin>>q;
	ll y;
	while(q--)
	{
		scanf("%I64d%I64d",&x,&y);
		ll a=query(x);
		printf("%I64d\n",a);
		change(x,a+y);
	}
	return 0;
}