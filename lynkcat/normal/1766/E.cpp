// Problem: E. Decomposition
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms

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
#define N 500005
using namespace std;
int n,a[N],S[4][105];	
void merge(int &x,int &y)
{
	y+=x;
	x=0;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	int lst=0;
	int sm=0;
	int ss=0;
	int ans1=0;
	for (int i=1;i<=n;i++)
	{
		S[0][0]++;
		if (a[i]==3)
		{
			for (int j=0;j<4;j++)
			{
				merge(S[1][j],S[3][j]);
				merge(S[2][j],S[3][j]);
				merge(S[0][j],S[3][j]);
			}
		} else
		if (a[i]==1)
		{
			for (int j=0;j<4;j++)
			{
				merge(S[3][j],S[1][j]);
				merge(S[0][j],S[1][j]);
				if ((j)%2==0)
				{
					ss+=S[2][j];
					merge(S[2][j],S[2][j|1]);
				}
			}
		} else
		if (a[i]==2)
		{
			for (int j=0;j<4;j++)
			{
				merge(S[3][j],S[2][j]);
				merge(S[0][j],S[2][j]);
				if ((j>>1)%2==0)
				{
					ss+=S[1][j];
					merge(S[1][j],S[1][j|2]);
				}
			}
		}
		if (a[i]==0)
		{
			sm+=i;
		} else
		{
			lst=i;
			for (int j=0;j<4;j++)
				ans-=S[0][j];
		}
		ans+=sm;
		ans+=lst;
		ans+=ss;
		// for (int l=1;l<=i;l++)
		// {
			// poly g;
			// for (int j=l;j<=i;j++)
			// {
				// int bl=0;
				// for (int k=0;k<g.size();k++)
				// {
					// if (g[k]&a[j])
					// {
						// g[k]=a[j];
						// bl=1;
						// break;
					// }
				// }
				// if (!bl) 
				// {
					// g.push_back(a[j]);
				// }
			// }
			// ans1+=g.size();
			// // cout<<l<<" "<<i<<" "<<g.size()<<'\n';
		// }
		// cout<<"?"<<i<<" "<<ans<<" "<<ans1<<'\n';
	}
	cout<<ans<<'\n';
			
				
			
		
		
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}