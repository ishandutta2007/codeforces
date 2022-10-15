// Lynkcat.
// Problem: B. Missing Bigram
// URL: https://codeforces.com/contest/1618/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define N 105
using namespace std;
int n;
string a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n-2;i++) cin>>a[i];
	string nowst=a[1];
	for (int i=2;i<=n-2;i++)
		if (a[i-1][1]!=a[i][0])
		{
			// nowst+='a';
			nowst+=a[i];
		} else nowst+=a[i][1];
	// cout<<nowst<<endl;
	if (nowst.size()!=n) nowst+='a';
	cout<<nowst<<endl;
			
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