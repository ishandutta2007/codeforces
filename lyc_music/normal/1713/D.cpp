// Lynkcat.
// Problem: D. Tournament Countdown
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/D
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
// #define N 
using namespace std;
int n;
void BellaKira()
{
	cin>>n;
	poly a;
	int ans=0;
	for (int i=1;i<=(1<<n);i++) a.push_back(i);
	while (a.size())
	{
		if (a.size()==1) 
		{
			ans=a[0];
			break;
		}
		if (a.size()==2)
		{
			cout<<"? "<<a[0]<<" "<<a[1]<<endl;
			int x;
			cin>>x;
			if (x==1) ans=a[0];
			else ans=a[1];
			break;
		}
		poly nxt;
		for (int i=0;i<a.size();i+=4)
		{
			int x=0;
			cout<<"? "<<a[i]<<" "<<a[i+2]<<endl;
			cin>>x;
			if (x==0)
			{
				int y=0;
				cout<<"? "<<a[i+1]<<" "<<a[i+3]<<endl;
				cin>>y;
				if (y==1) nxt.push_back(a[i+1]);
				else nxt.push_back(a[i+3]);
			} else
			if (x==1)
			{
				int y=0;
				cout<<"? "<<a[i]<<" "<<a[i+3]<<endl;
				cin>>y;
				if (y==1) nxt.push_back(a[i]);
				else nxt.push_back(a[i+3]);
			} else
			{
				int y=0;
				cout<<"? "<<a[i+1]<<" "<<a[i+2]<<endl;
				cin>>y;
				if (y==1) nxt.push_back(a[i+1]);
				else nxt.push_back(a[i+2]);
			}
		}
		swap(a,nxt);
	}
	cout<<"! "<<ans<<endl;
				
				
			
			
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