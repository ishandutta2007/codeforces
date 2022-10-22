#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
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
#define For(I,N) for(int I=0;I<N;I++)
const int mod=100000000;
typedef unsigned long long ull;
using namespace std;
int s,h,ks,kh;//0 1 
int dp[105][105][2];

int dfs(int ft,int hs,bool who) //fthswho
{
//	cout<<ft<<' '<<hs<<' '<<who<<endl;
	if(dp[ft][hs][who]!=-1) return dp[ft][hs][who];
	if(ft==0 && hs<=kh && who==1) return 1;
	if(hs==0 && ft<=ks && who==0) return 1;
	if(who==0)
	{
		int s=0;
		for(int i=1;i<=ks;i++)
		{
			if(ft-i<0) break;
			s+=dfs(ft-i,hs,1);
			s%=mod;
		}
		return dp[ft][hs][who]=s%mod;
	}
	else
	{
		int s=0;
		for(int i=1;i<=kh;i++)
		{
			if(hs-i<0) break;
			s+=dfs(ft,hs-i,0);
			s%=mod;
		}
		return dp[ft][hs][who]=s%mod;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>s>>h>>ks>>kh;
//	cout<<dfs(s,h,false)<<endl;
//	cout<<dfs(s,h,true)<<endl;
	cout<<(dfs(s,h,false)+dfs(s,h,true))%mod<<endl;
	return 0;
}