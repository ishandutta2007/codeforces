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
int n,a,b;

void print(int x,int k)
{
	printf("%d ",k+x);
	for(int i=k+1;i<=k+x-1;i++)
	{
		printf("%d ",i); 
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>a>>b;
	int sa,sb=-1;
	for(sa=0;sa<=(int)(n/a);sa++)
	{
		if((n-sa*a)%b==0)
		{
			sb=(n-sa*a)/b;
			break;
		}
	}
	if(sb==-1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<sa;i++)
	{
		print(a,i*a);
	}
	for(int j=0;j<sb;j++)
	{
		print(b,sa*a+j*b);
	}
	return 0;
}