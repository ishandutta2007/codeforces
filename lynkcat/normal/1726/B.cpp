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
	if (m<n)
	{
		cout<<"No"<<endl;
		return;
	}
	if (n==1)
	{
		cout<<"Yes"<<endl;
		cout<<m<<endl;
	}else
	{
		if (n%2==1)
		{
			cout<<"Yes"<<endl;
			for (int i=1;i<n;i++)
				cout<<1<<" ";
			cout<<m-(n-1)<<endl;
			return;
		}
		if (m%2==1)
		{
			cout<<"No"<<endl;
			return;
		}
		cout<<"Yes"<<endl;
		for (int i=1;i<=n-2;i++) cout<<1<<" ";
		cout<<(m-(n-2))/2<<" "<<(m-(n-2))/2<<endl;
	}
			
}
signed main()
{
	IOS;cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}