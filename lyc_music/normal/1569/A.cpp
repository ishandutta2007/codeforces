// Lynkcat.
// Problem: A. Balanced Substring
// URL: https://codeforces.com/contest/1569/problem/A
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
//#define N
using namespace std;
void BellaKira()
{
	map<int,int>Mp;
	Mp[0]=0;
	int now=0;
	int n;
	cin>>n;
	string st;
	cin>>st;
	int nowp=0;
	int tt=0;
	for (auto u:st)
	{
		++tt;
		if (u=='a') now++;
		else now--;
		if (Mp.count(now))
		{
			cout<<Mp[now]+1<<" "<<tt<<endl;
			nowp=1;
			break;
		}
		Mp[now]=tt;
	}
	if (!nowp) cout<<-1<<" "<<-1<<endl;
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