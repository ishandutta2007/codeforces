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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;

ll cf(int x)
{
	ll s=1LL;
	for(int i=0;i<x;i++)
	{
		s*=10LL;
	}
	return s;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,mod;
	cin>>n>>mod;
	ll s=0LL;
	for(int i=1;i<=n;i++)
	{
		int x=i;
		int y=0;
		int len=0;
		while(x)
		{
			len++;
			y=y*10+x%10;
			x/=10;
		}
//		cout<<
		s=(s+1LL*y+1LL*cf(len)*i)%mod;
	}
	cout<<s<<endl;
	return 0;
}