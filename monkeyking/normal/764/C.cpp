#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define Endl endl
using namespace std;
int n;
vector <int> vec[100005];
int a[100005];
int dp[100005];
int fuck;

int dfs(int x,int p)
{
//	cout<<x<<' '<<p<<endl;
	dp[x]=-1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		int t=dfs(vec[x][i],x);
		if(t==-2)
		{
			return -2;
		}
		else if(t==-1)
		{
			t=a[vec[x][i]];
		}
		else if(t==a[vec[x][i]])
		{
			;
		}
		else
		{
//			cout<<vec[x][i]<<endl;
			fuck=vec[x][i];
			return -2;
		}
//		cout<<t<<endl;
		if(dp[x]==-1)
		{
			dp[x]=t;
		}
		else if(dp[x]==t)
		{
			;
		}
		else
		{
			fuck=x;
			return -2;
		}
	}
	return dp[x];
}

bool ok(int x,int p,int c)
{
	if(a[x]!=c) return false;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		if(!ok(vec[x][i],x,c)) return false;
	}
	return true;
}

bool go(int x)
{
	for(int i=0;i<vec[x].size();i++)
	{
		if(!ok(vec[x][i],x,a[vec[x][i]])) return false;
	}
	return true;
}

int main()
{
	fuck=-1;
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	dfs(0,-1);
//	cout<<dp[3]<<endl;
//	cout<<fuck<<endl;
	if(fuck==-1)
	{
		cout<<"YES\n1\n";
	}
	else
	{
		if(go(fuck))
		{
			cout<<"YES\n";
			cout<<fuck+1<<endl;
		}
		else
		{
			cout<<"NO\n";
		}
	}
//	cout<<fuck<<endl;
	return 0;
}