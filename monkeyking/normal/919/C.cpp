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
typedef unsigned long long ull;
using namespace std;
int n,m,k;
int row[2005][2005];
int cal[2005][2005];
char map[2005][2005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
	}
	for(int i=0;i<n;i++)
	{
		row[i][0]=(map[i][0]=='.');
	}
	for(int i=0;i<m;i++)
	{
		cal[0][i]=(map[0][i]=='.');
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			row[i][j]=row[i][j-1]+(map[i][j]=='.');
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cal[i][j]=cal[i-1][j]+(map[i][j]=='.');
		}
	}
	int ans=0;
	for(int i=0;i<n-k;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(cal[i+k][j]-cal[i][j]==k) ans++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-k;j++)
		{
			if(row[i][j+k]-row[i][j]==k) ans++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(row[i][max(0,k-1)]==k) ans++;
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<cal[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=0;i<m;i++)
	{
		if(cal[max(0,k-1)][i]==k) ans++;
	}
	if(k==1) ans/=2;
	cout<<ans<<endl;
	return 0;
}