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
int type[105];
int a[105];

bool check(int x)
{
	if(x==0) return true;
	int sum=0;
	for(int i=0;i<=100;i++)
	{
		sum+=a[i]/x;
	}
	return (sum>=n);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	rep(m)
	{
		cin>>type[i];
		a[type[i]-1]++;
	}
	for(int i=100;i>=0;i--)
	{
		if(check(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}