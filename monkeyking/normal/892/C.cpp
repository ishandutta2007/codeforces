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
#define inf 28340123
typedef unsigned long long ull;
using namespace std;

int gcd(int a,int b)
{
	int c;
	while(a!=b && b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cinone(n);
	cingroup(a,n);
	int s=0;
	rep(n)
	{
		s+=(a[i]==1);
	}
	if(s)
	{
		cout<<n-s<<endl;
		return 0;
	}
	int now,minl=inf;
	for(int i=0;i<n-1;i++)
	{
		now=a[i];
		for(int j=1;j<n-i;j++)
		{
			now=gcd(now,a[i+j]);
			if(now==1 && minl>j) minl=j;
		}
	}
	if(minl!=inf)
	{
		cout<<n+minl-1<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}