// Lynkcat.
// Problem: B. ICPC Balloons
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/B
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
int n;
string st;
void BellaKira()
{
	cin>>n;
	cin>>st;
	int ans=0;
	map<int,int>Mp;
	for (int i=0;i<st.size();i++)
	{
		if (!Mp.count(st[i])) ans+=2;
		else ans+=1;
		Mp[st[i]]=1;
	}
	cout<<ans<<endl;
		
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