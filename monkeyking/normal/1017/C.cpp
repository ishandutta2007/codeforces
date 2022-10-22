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
int res[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		res[i]=i+1;
	}
	reverse(res,res+n);
	int x=sqrt(n);
//	cout<<x<<endl;
	if(x*x==n)
	{
		for(int i=0;i<x;i++)
		{
			reverse(res+i*x,res+i*x+x);
		}
	}
	else/* if(x*(x+1)<=n)*/
	{
		int len=n/(x+1);
		int remain=n%(x+1);
		x++;
		reverse(res,res+remain);
		for(int i=0;i<len;i++)
		{
			reverse(res+remain+i*x,res+remain+i*x+x);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",res[i]);
	}
	return 0;
}