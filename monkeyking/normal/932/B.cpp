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
int g[1000005];
int sum[1000005][10];

int cal(int x)
{
	int ans=1;
	while(x)
	{
		if(x%10)
		{
			ans*=(x%10);
		}
		x/=10;
	}
	return g[ans];
}

int main()
{
//	freopen("input.txt","r",stdin);
	for(int i=1;i<10;i++)
	{
		g[i]=i;
	}
	for(int i=10;i<=1000000;i++)
	{
		g[i]=cal(i);
	}
	for(int i=1;i<=1000000;i++)
	{
		for(int j=1;j<=9;j++)
		{
			sum[i][j]=sum[i-1][j]+(g[i]==j);
		}
	}
	int q;
	cin>>q;
	int l,r,k;
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&k);
		cout<<sum[r][k]-sum[l-1][k]<<endl;
	}
	return 0;
}