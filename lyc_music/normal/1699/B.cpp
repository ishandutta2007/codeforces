// Lynkcat.
// Problem: B. Almost Ternary Matrix
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/B
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
int n,m;
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (((i-1)/2)%2==1)
			{
				if (i%2)
				{
					if (j%4==1||j%4==0) cout<<1;
					else cout<<0;
				}
				else 
				{
					if (j%4==2||j%4==3) cout<<1;
					else cout<<0;
				}
			}
			else
			{
				if (i%2==0)
				{
					if (j%4==1||j%4==0) cout<<1;
					else cout<<0;
				}
				else 
				{
					if (j%4==2||j%4==3) cout<<1;
					else cout<<0;
				}
			}
			cout<<" ";
		}
		cout<<endl;
	}
			
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