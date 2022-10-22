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
bool dp[1005][2005];
int n,k;
char c[1005];
char road[1005][2005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	scanf("%s",c);
	if(n==1)
	{
		if(k==0) cout<<'D';
		else if(k==1) cout<<'W';
		else cout<<"NO\n";
		return 0;
	}
	if(c[0]=='W') dp[0][1001]=true,road[0][1001]='W';
	else if(c[0]=='L') dp[0][999]=true,road[0][999]='L';
	else if(c[0]=='D') dp[0][1000]=true,road[0][1000]='D';
	else
	{
		dp[0][1000]=dp[0][1001]=dp[0][999]=true;
		road[0][1001]='W';
		road[0][1000]='D';
		road[0][999]='L';
	}
	if(dp[0][1000-k] || dp[0][1000+k])
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<2000;j++)
		{
			if(i!=(n-1) && (j==1000+k || j==1000-k)) continue;
			if(c[i]=='W')
			{
				dp[i][j]=dp[i-1][j-1];
				road[i][j]='W';
			}
			else if(c[i]=='L')
			{
				dp[i][j]=dp[i-1][j+1];
				road[i][j]='L';
			}
			else if(c[i]=='D')
			{
				dp[i][j]=dp[i-1][j];
				road[i][j]='D';
			}
			else
			{
				dp[i][j]=dp[i-1][j-1] | dp[i-1][j] | dp[i-1][j+1];
				if(dp[i-1][j-1])
				{
					road[i][j]='W';
				}
				else if(dp[i-1][j])
				{
					road[i][j]='D';
				}
				else if(dp[i-1][j+1])
				{
					road[i][j]='L';
				}
			}
		}
	}
	if(!(dp[n-1][1000-k] || dp[n-1][1000+k]))
	{
		cout<<"NO\n";
		return 0;
	}
	int now;
	if(dp[n-1][1000-k]) now=1000-k;else now=1000+k;
	for(int i=n-1;i>=0;i--)
	{
		c[i]=road[i][now];
		if(road[i][now]=='L')
		{
			now++;
		}
		else if(road[i][now]=='W')
		{
			now--;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}