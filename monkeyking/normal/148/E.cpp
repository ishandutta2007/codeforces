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
int n,m;
int a[105][105];
int len[105];
int dp[10005];
int sum[105][105];
int best[105][105];
int sr[105][105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>len[i];
		for(int j=0;j<len[i];j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		sum[i][0]=a[i][0];
		for(int j=1;j<len[i];j++)
		{
			sum[i][j]=sum[i][j-1]+a[i][j];
			best[i][j+1]=max(best[i][j+1],sum[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		sr[i][len[i]-1]=a[i][len[i]-1];
		for(int j=len[i]-2;j>=0;j--)
		{
			sr[i][j]=sr[i][j+1]+a[i][j];
			best[i][len[i]-j]=max(best[i][len[i]-j],sr[i][j]);
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<len[i];j++)
//		{
//			cout<<sum[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=0;i<n;i++)
	{
		best[i][0]=0;
		best[i][1]=max(a[i][0],a[i][len[i]-1]);
		for(int j=0;j<len[i];j++)
		{
			for(int k=j+1;k<len[i];k++)
			{
//				cout<<sum[i][j]+sr[i][k]<<endl;
//				if(j+len[i]-k+1==2) cout<<best[i][j+len[i]-k+1];//cout<<sum[i][j]+sr[i][k]<<endl;
				best[i][j+len[i]-k+1]=max(best[i][j+len[i]-k+1],sum[i][j]+sr[i][k]);
			}
		}
	}
//	for(int i=0;i<len[0];i++)
//	{
//		for(int j=i+1;j<len[0];j++)
//		{
//			if(i+len[0]-j+1!=2) continue;
//			cout<<sum[0][i]+sr[0][j]<<endl;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=len[i];j++)
//		{
//			cout<<best[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=0;i<n;i++)
	{
		for(int k=m;k>=0;k--)
		{
			for(int j=0;j<=len[i];j++)
			{
				if(k-j<0) continue;
				dp[k]=max(dp[k],dp[k-j]+best[i][j]);
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}