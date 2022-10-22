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
int n,ans=0;

int dfs(int k)
{
	int s=0;
	if(k==1)
	{
		return(ans<=n);
	}
	else
	{
		ans*=10;
		s+=dfs(k-1);
		ans+=1;
		s+=dfs(k-1);
		ans/=10;
		return s;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	cout<<dfs(11)-1<<endl;
	return 0;
}