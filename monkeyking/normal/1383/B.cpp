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
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int dp[20][20][2][2];
int a[100005];
int n;

int dfs(int x,int y,int a,int b)//1-win 0-draw -1 -lose
{
	if(dp[x][y][a][b]!=-2) return dp[x][y][a][b];
	int &best=dp[x][y][a][b];
	if(x==0 && y==0) return best=a-b;
//	if(x==1 && y==0) cout<<dfs(0,0,0,1)<<endl;
//	if(a==0 && b==0 && x%2==0 && x && y) cout<<dfs(x-1,y,b,a^1)<<' '<<dfs(x,y-1,b,a)<<endl;
	if(x) chmax(best,-dfs(x-1,y,b,a^1));
	if(y) chmax(best,-dfs(x,y-1,b,a));
	return best;
}

void solve()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int k=30;k>=0;k--)
	{
		int s0=0,s1=0;
		for(int i=0;i<n;i++)
		{
			if((1<<k) & a[i]) s1++;else s0++;
		}
		if(s1%2==0) continue;
		if(s1%4==1)
		{
			puts("WIN");
			return;
		}
		if(s0%2==1)
		{
			puts("WIN");
			return;
		}
		puts("LOSE");
		return;
	}
	puts("DRAW");
}

int main()
{
//	freopen("input.txt","r",stdin);
//	for(int i=0;i<20;i++)
//	{
//		for(int j=0;j<20;j++)
//		{
//			for(int k=0;k<2;k++)
//			{
//				for(int l=0;l<2;l++)
//				{
//					dp[i][j][k][l]=-2;
//				}
//			}
//		}
//	}
//	for(int i=0;i<20;i++)
//	{
//		for(int j=0;j<20;j++)
//		{
////			dfs(j,i,0,0);
////			printf("%2d ",dfs(j,i,0,0));
////			cout<<dfs(j,i,0,0)<<' ';
//		}
//		cout<<endl;
//	}
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}