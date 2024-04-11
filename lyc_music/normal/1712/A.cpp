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
// #define int ll
#define N 10005
using namespace std;
int n,m,a[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	int x=0;
	for (int i=1;i<=m;i++)
		if (a[i]>m) x++;
	cout<<x<<endl;
		
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