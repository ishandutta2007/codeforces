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
int n;
int a[100];

void dfs(int k,int remain)
{
//	if(k>=48)
//	{
//		cout<<k<<' '<<remain<<endl;
//	}
	if(k==50)
	{
		if(remain==10) return;
		n--;
		if(n==0)
		{
			int i;
			for(i=0;i<=50;i++)
			{
				if(a[i]!=0) break;
			}
			for(;i<50;i++)
			{
				cout<<a[i];
			}
			cout<<remain<<endl;
			exit(0);
		}
	}
	else
	{
		for(int i=0;i<=min(remain,9);i++)
		{
			a[k]=i;
			dfs(k+1,remain-i);
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	dfs(0,10);
//	a[50]=9;
//	a[49]=1;
//	int len=50;
//	int t;
//	while(--k)
//	{
//		t=50;
//		a[len]--;
//		a[len-1]++;
//		while(a[t]<=0)
//		{
//			a[t]=0;
//			a[t-1]=0;
//			a[t-2]++;
//			t-=2;
//		}
//	}
//	int i;
//	for(i=0;i<=50;i++)
//	{
//		if(a[i]!=0) break;
//	}
//	for(;i<=50;i++)
//	{
//		cout<<a[i];
//	}
//	cout<<endl;
	return 0;
}