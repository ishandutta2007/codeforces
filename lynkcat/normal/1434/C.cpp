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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int o=b*c;
	if (o<a) cout<<"-1\n";
	else
	{
		int n=(a-1)/(b*d);
		cout<<(n+1)*a-(1+n)*n/2*b*d<<'\n';
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