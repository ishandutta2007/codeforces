// Lynkcat.
// Problem: D. Double Strings
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define N 100005
using namespace std;
int n;
string a[N];
void BellaKira()
{
	map<string,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		Mp[a[i]]++;
	}
	for (int i=1;i<=n;i++)
	{
		int ans=0;
		for (int j=0;j+1<a[i].size();j++)
		{
			string x="",y="";
			for (int k=0;k<=j;k++) x+=a[i][k];
			for (int k=j+1;k<a[i].size();k++) y+=a[i][k];
			if (Mp.count(x)&&Mp.count(y)) ans=1;
		}
		cout<<ans;
	}
	cout<<endl;
		
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}