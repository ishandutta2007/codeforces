// Problem: M. Bottle Arrangements
// URL: https://codeforces.com/contest/1662/problem/M
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// //

//~~
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
poly gt(int x,int p)
{
	poly res;
	for (int i=1;i*i<=x;i++)
	{
		if (x%i==0)
		{
			if (p%i==0)	res.push_back(i);
			if (i*i!=x) 
			{
				if (p%(x/i)==0)
					res.push_back(x/i);
			}
		}
	}
	return res;
}
void BellaKira()
{
	int n,m;
	cin>>n>>m;
	if (n<m) swap(n,m);
	poly G;
	poly nowx=gt(m-1,n-1);
	poly nowy=gt(m,n-2);
	poly nowz=gt(m-2,n);
	
	for (auto u:nowx)
		if ((n-1)%u==0) G.push_back(u);
	for (auto u:nowy)
		if ((n-2)%u==0) G.push_back(u);
	for (auto u:nowz)
		if (n%u==0) G.push_back(u);
    n+=2;
    if(n%2==1&&m%2==0)
    {
        G.push_back(2);
    }
    if(n%2==0&&m%2==1)
    {
        G.push_back(2);
    }
	sort(G.begin(),G.end());
	G.erase(unique(G.begin(),G.end()),G.end());
	cout<<G.size()<<" ";
	for (auto u:G) cout<<u<<" ";
	cout<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/