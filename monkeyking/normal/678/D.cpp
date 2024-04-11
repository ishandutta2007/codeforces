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
ll sum,pw;

void cal(ll a,ll k)
{
	if(k==0)
	{
		sum=0;
		pw=1;
		return;
	}
	cal(a,k/2);
	sum=(sum+pw*sum)%mod;
	pw=pw*pw;
	pw%=mod;
	if(k&1)
	{
		sum=(sum+pw)%mod;
		pw=pw*a;
		pw%=mod;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll a,b,n,x;
	cin>>a>>b>>n>>x;
	cal(a,n);
	cout<<(pw*x+sum*b)%mod<<endl;
	return 0;
}