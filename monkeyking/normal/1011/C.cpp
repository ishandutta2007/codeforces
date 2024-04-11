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
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
int a[1005],b[1005];
long double res;

long double cal(long double x,long double cost)
{
	long double t=x/(cost-1);
	return x+t;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",b+i);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1 || b[i]==1) over(-1);
	}
	res=m;
	res=cal(res,(long double)b[0]);
	for(int i=1;i<n;i++)
	{
		res=cal(res,a[i]);
		res=cal(res,b[i]);
	}
	res=cal(res,a[0]);
	cout.precision(10);
	cout<<res-m<<endl;
	return 0;
}