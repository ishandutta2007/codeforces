#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
int n;
int map[205][205];
char pe[4][105][105];
int num[4]={0,1,2,3};
const int dx[]={0,1,0,1};
const int dy[]={0,0,1,1};

void rebuild()
{
	for(int k=0;k<4;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				map[i+dx[k]*n][j+dy[k]*n]=pe[num[k]][i][j];
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%s",pe[i][j]);
		}
	}
	int m1[205][205],m2[205][205];
	for(int i=0;i<203;i++)
	{
		for(int j=0;j<203;j++)
		{
			m1[i][j]=(char)((i+j)%2+'0');
			m2[i][j]='1'-m1[i][j]+'0';
		}
	}
	int res=inf;
	do
	{
		int a=0,b=0;
		rebuild();
//		for(int i=0;i<2*n;i++)
//		{
//			for(int j=0;j<2*n;j++)
//			{
//				cout<<(char)map[i][j];
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
			{
				a+=(map[i][j]!=m1[i][j]);
				b+=(map[i][j]!=m2[i][j]);
			}
		}
		res=min(res,a);
		res=min(res,b);
	}while(next_permutation(num,num+4));
	cout<<res<<endl;
	return 0;
}