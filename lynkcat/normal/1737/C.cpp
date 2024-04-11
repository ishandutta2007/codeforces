// Problem: C. Ela and Crickets
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
int x[5],y[5];
void BellaKira()
{
	int n;
	cin>>n;
	int ox=0,oy=0;
	int ans=0;
	map<pa,int>Mp;
	for (int i=1;i<=3;i++)
		cin>>x[i]>>y[i],ox^=x[i],oy^=y[i],Mp[mp(x[i],y[i])]++;
	for (int i=1;i<=3;i++) 
		if (ox!=x[i])
		{
			ox=x[i];
			break;
		}
	for (int i=1;i<=3;i++) 
		if (oy!=y[i])
		{
			oy=y[i];
			break;
		}
	int X,Y;
	cin>>X>>Y;
	if ((ox==1||ox==n)&&(oy==1||oy==n))
	{
		if (X==ox||Y==oy) cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}
	if ((ox%2!=X%2)&&(oy%2!=Y%2)) return cout<<"NO\n",void();
	cout<<"YES\n";
		
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