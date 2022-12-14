// Lynkcat.
// Problem: F. 3SUM
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
// #define N 
using namespace std;
int n,a[200005];
void BellaKira()
{
	int ans=0;
	map<int,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],Mp[a[i]%10]++;
	for (int i=0;i<=9;i++)
	if (Mp[i])
	{
		Mp[i]--;
		for (int j=0;j<=9;j++)
		if (Mp[j])
		{
			Mp[j]--;
			for (int k=0;k<=9;k++)
			if (Mp[k])
			{
				if ((i+j+k)%10==3) ans=1;
			}
			Mp[j]++;
		}
		Mp[i]++;
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
				
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