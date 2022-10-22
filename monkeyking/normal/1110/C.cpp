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
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int ans[]={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int solve(int x)
{
	int maxn=0,k=-1;
	for(int i=1;i<x;i++)
	{
		int t=__gcd(i^x,i&x);
		if(t>maxn)
		{
			maxn=t;
			k=i;
		}
	}
	return maxn;
}

int lenof(int x)
{
	int len=0;
	while(x)
	{
		len++;
		x>>=1;
	}
	return len;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		int len=lenof(x);
		if(x!=(1<<len)-1)
		{
			cout<<(1<<len)-1<<endl;
		}
		else
		{
			cout<<ans[len-2]<<endl;
		}
	}
//	cout<<solve(255)<<endl;
	return 0;
}