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
set <ll> squ;
ll n;
bool use[15];

int lenof(int x)
{
	int len=0;
	while(x)
	{
		len++;
		x/=10;
	}
	return len;
}

void dfs(ll num,ll x,ll y)
{
	if(num>n) return;
	squ.insert(num);
	dfs(num*10+x,x,y);
	dfs(num*10+y,x,y);
}

int main()
{
	cin>>n;
	for(ll i=0;i<=9;i++)
	{
		for(ll j=i+1;j<=9;j++)
		{
			if(i) dfs(i,i,j);
			dfs(j,i,j);
		}
	}
	cout<<squ.size()<<endl;
	return 0;
}