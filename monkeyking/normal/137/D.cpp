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
char c[505];
int n;
int m;
int need[505][505];
int dp[505][505];
pii road[505][505];

int check(int l,int r)
{
	int res=0;
	for(int i=l;i<(l+r+1)/2;i++)
	{
		if(c[i]!=c[r-i+l]) res++;
	}
	return res;
}

void change(int l,int r)
{
	for(int i=l;i<(l+r+1)/2;i++)
	{
		if(c[i]!=c[r-i+l]) c[r-i+l]=c[i];
	}
	for(int i=l;i<=r;i++)
	{
		cout<<c[i];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(road,-1,sizeof(road));
	memset(dp,0x3f,sizeof(dp));
	scanf("%s",c);
	n=strlen(c);
	cin>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			need[i][j]=check(i,j);
//			cout<<need[i][j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		dp[i][1]=need[0][i];
	}
//	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m-1;j++)
		{
			for(int k=i+1;k<n;k++)
			{
				if(dp[i][j]+need[i+1][k]<dp[k][j+1])
				{
					dp[k][j+1]=dp[i][j]+need[i+1][k];
					road[k][j+1]=mp(i,j);
				}
//				dp[k][j+1]=min(dp[k][j+1],dp[i][j]+need[i+1][k]);
			}
		}
	}
	int res=dp[n-1][0];
	int id=0;
	for(int i=1;i<=m;i++)
	{
		if(dp[n-1][i]<res)
		{
			res=dp[n-1][i];
			id=i;
		}
	}
	cout<<res<<endl;
	int x=n-1,y=id;
	vector <int> ans;
	while(1)
	{
		ans.push_back(x);
		pii t=road[x][y];
		x=t.first;
		y=t.second;
		if(x==-1 || y==-1) break;
	}
	reverse(ans.begin(),ans.end());
//	ans.pop_back();
	int len=ans.size();
	change(0,ans[0]);
	for(int i=0;i<len-1;i++)
	{
		cout<<'+';
		change(ans[i]+1,ans[i+1]);
	}
//	cout<<len<<endl;
//	ans.pop_back();
//	len=ans.size();
//	cout<<len<<endl;
//	ans.pop_back();
//	ans.pop_back();
//	int j=0;
//	for(int i=0;i<n;i++)
//	{
//		cout<<c[i];
//		if(i==ans[j]) cout<<'+',j++;
//	}
//	for(int i=0;i<ans.size();i++)
//	{
//		cout<<ans[i]<<' ';
//	}
//	cout<<Endl;
	return 0;
}