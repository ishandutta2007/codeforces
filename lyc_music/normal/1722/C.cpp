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
// #define N 
using namespace std;
int n;
int ans[5];
void BellaKira()
{
	map<string,poly>Mp;
	cin>>n;
	for (int i=1;i<=3;i++)
	{
		ans[i]=0;
		for (int j=1;j<=n;j++)
		{
			string st;
			cin>>st;
			Mp[st].push_back(i);
		}
	}
	for (auto [u,v]:Mp)
	{
		if (v.size()==3) continue;
		if (v.size()==2)
		{
			for (auto i:v) ans[i]++;
		}
		else
			ans[v[0]]+=3;
	}
	for (int i=1;i<=3;i++) cout<<ans[i]<<" ";
	cout<<endl;
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