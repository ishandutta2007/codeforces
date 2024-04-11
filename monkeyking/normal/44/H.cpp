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
typedef unsigned long long ull;
using namespace std;
long long  dp[55][15],a[55],len; 

long long dfs(int k,int who)
{
	if(dp[k][who]!=-1) return dp[k][who];
	if(k==len-1) return 1;
	if((who+a[k+1])%2==0)
	{
		return dp[k][who]=dfs(k+1,(who+a[k+1])/2);
	}
	else
	{
		return dp[k][who]=dfs(k+1,(who+a[k+1])/2)+dfs(k+1,(who+a[k+1])/2+1);
	}
//	return dp[k][who]=dfs(k+1,a[k])+dfs(k+1,(a[k]+1)%2);
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	string c;
	cin>>c;
	len=c.size();
	for(int i=0;i<len;i++)
	{
		a[i]=(c[i]-'0');
	}
	long long s=0;
	for(int i=0;i<=9;i++)
	{
		s+=dfs(0,i);
	}
	bool f=false;
	for(int i=1;i<len;i++)
	{
		if((a[i]+a[i-1])/2!=a[i] && (a[i]+a[i-1]+1)/2!=a[i]) f=true;
	}
	s-=!f;
	cout<<s<<endl;
	return 0;
}