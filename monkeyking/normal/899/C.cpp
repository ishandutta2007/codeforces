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

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	if(n%4==0)
	{
		cout<<0<<endl;
		cout<<n/2<<' ';
		for(int i=1;i<=n/4;i++)
		{
			cout<<i<<' ';
		}
		for(int i=n;i>n-n/4;i--)
		{
			cout<<i<<' ';
		}
		cout<<endl;
	}
	else if(n%4==2)
	{
		cout<<1<<endl;
		cout<<n/2<<' ';
		for(int i=1;i<n/2;i++)
		{
			if(i%2) cout<<i<<' ';
		}
		for(int i=n/2+1;i<=n;i++)
		{
			if(i%2==0) cout<<i<<' ';
		}
	}
	else if(n%4==1)
	{
		cout<<1<<endl;
		cout<<n/2<<' ';
		for(int i=2;i<=n;i++)
		{
			if(i%4==2 || i%4==1) cout<<i<<' ';
		}
	}
	else
	{
		cout<<0<<Endl;
		cout<<n/2<<' '<<3<<' ';
		for(int i=4;i<=n;i++)
		{
			if(i%4==0 || i%4==3) cout<<i<<' ';
		}
	}
	return 0;
}