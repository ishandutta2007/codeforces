// Lynkcat.
// Problem: B. Peculiar Movie Preferences
// URL: https://codeforces.com/contest/1628/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
int n;
string a[100005];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	map<string,int>Mp;
	map<string,int>Mp1;
	//calc 1 1
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()==1)
		{
			ans=1;
		}
	}
	Mp.clear();
	//calc 2 2 
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()==2)
		{
			if (a[i][0]==a[i][1]) ans=1;
			
			string now="";
			now+=a[i][1];
			now+=a[i][0];
			if (Mp.count(now))
			{
				ans=1;
			}
			Mp[a[i]]=1;
			
		}
	}
	Mp.clear();
	//calc 3 3
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()==3)
		{
			if (a[i][0]==a[i][2]) ans=1;
			string now="";
			now+=a[i][2];
			now+=a[i][1];
			now+=a[i][0];
			if (Mp.count(now))
			{
				ans=1;
			}
			Mp[a[i]]=1;
		}
	}
	Mp.clear();
	
	//calc 2 3
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()==2)
		{
			Mp[a[i]]=1;
		} else
		if (a[i].size()==3)
		{
			if (a[i][0]==a[i][2]) ans=1;
			string now="";
			now+=a[i][2];
			now+=a[i][1];
			if (Mp.count(now))
			{
				ans=1;
			}
		}
	}
	Mp.clear();
	//calc 2 3
	for (int i=n;i>=1;i--)
	{
		if (a[i].size()==2)
		{
			reverse(a[i].begin(),a[i].end());
			Mp[a[i]]=1;
			reverse(a[i].begin(),a[i].end());
		} else
		if (a[i].size()==3)
		{
			reverse(a[i].begin(),a[i].end());
			string now="";
			now+=a[i][2];
			now+=a[i][1];
			if (Mp.count(now))
			{
				ans=1;
			}
			reverse(a[i].begin(),a[i].end());
		}
	}
	Mp.clear();
	
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}