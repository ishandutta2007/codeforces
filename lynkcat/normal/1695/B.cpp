// Lynkcat.
// Problem: B. Circle Game
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/B
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
#define N  55
using namespace std;
int n,a[N];
int s[2],pos[2];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n%2==1) return cout<<"Mike"<<endl,void();
	else
	{
		s[0]=inf,s[1]=inf;
		for (int i=1;i<=n;i++) 
			if (a[i]<s[i%2]) s[i%2]=min(s[i%2],a[i]),pos[i%2]=i;
		swap(s[0],s[1]),swap(pos[0],pos[1]);
		if (s[0]<s[1])
		{
			return cout<<"Joe"<<endl,void();
		} else if (s[1]<s[0]) cout<<"Mike"<<endl;
		else 
		{
			if (pos[0]<pos[1]) cout<<"Joe"<<endl;
			else cout<<"Mike"<<endl;
		}
	}
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