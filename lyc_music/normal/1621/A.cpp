// Lynkcat.
// Problem: A. Stable Arrangement of Rooks
// URL: https://codeforces.com/contest/1621/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
int n,m;
void BellaKira()
{
	cin>>n>>m;
	if (n%2==1)
	{
		if (m<=(n+1)/2)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
					if(i==j&&i%2==1&&(i+1)/2<=m) 
					{
						cout<<'R';
					}else
				cout<<'.';
				cout<<endl;
			}
		} else
		{
			cout<<-1<<endl;
		}
	} else
	{
		if (m<=(n+1)/2)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
					if(i==j&&i%2==1&&(i+1)/2<=m) 
					{
						cout<<'R';
					}else
				cout<<'.';
				cout<<endl;
			}
		} else
		{
			cout<<-1<<endl;
		}
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