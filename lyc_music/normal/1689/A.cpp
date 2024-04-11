// Lynkcat.
// Problem: A. Lex String
// URL: https://codeforces.com/contest/1689/problem/A
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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	string st,st1;
	int n,m,k;
	cin>>n>>m>>k;
	cin>>st>>st1;
	sort(st.begin(),st.end());
	sort(st1.begin(),st1.end());
	int i=0,j=0;
	string ans="";
	int x=0,y=0;
	while (i<n&&j<m)
	{
		if (x==k)
		{
			ans+=st1[j];
			j++;
			x=0,y=1;
		} else
		if (y==k)
		{
			ans+=st[i];
			i++;
			x=1,y=0;
		} else
		{
			if (st[i]<st1[j])
			{
				ans+=st[i];
				x++,y=0;
				i++;
			} else
			if (st[i]>st1[j])
			{
				ans+=st1[j];
				j++;
				y++,x=0;
			}
		}
	}
	cout<<ans<<endl;
	
	
	
			
	
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