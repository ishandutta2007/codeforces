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
void BellaKira()
{
	int n,m;
	cin>>n>>m;
	if (m==1) cout<<n-1<<endl;
	else cout<<n*(m-1)<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}