#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	if (n%2==0)
	{
		for (int i=1;i<=n;i+=2) cout<<i+1<<" "<<i<<" ";
		cout<<endl;
	} else
	{
		cout<<1<<" ";
		for (int i=2;i<=n;i+=2) cout<<i+1<<" "<<i<<" ";
		cout<<endl;
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}