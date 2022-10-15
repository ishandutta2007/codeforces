// Lynkcat.
// Problem: CF1693F I Might Be Wrong
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1693F
// Memory Limit: 250 MB
// Time Limit: 2000 ms

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
#define N 200005
using namespace std;
int n;
string st;
int a[N];
void BellaKira()
{
	cin>>n;
	cin>>st;
	if(is_sorted(st.begin(),st.end())){cout<<0<<endl;return;} 
	st=' '+st;
	int xx=0,yy=0;
	for (int i=1;i<=n;i++)
		if (st[i]=='0') xx++;
		else yy++;
	if (xx==yy)
	{
		cout<<1<<endl;
		return;
	}
	if (xx<yy)
	{
		for (int i=1;i<=n;i++)
			if (st[i]=='0') st[i]='1';
			else st[i]='0';
		for (int i=1;i<=n-i+1;i++)
			swap(st[i],st[n-i+1]);
	}
	xx=0;
	for (int i=1;i<=n;i++)
	{
		if (st[i]=='0') xx++;
		else  xx--;
		if (xx>=0) a[xx]=i-1;
	}
	int ans=0;
	int nw=0;
	// cout<<st<<endl;
	while (nw<n&&st[nw+1]=='0') nw++;
	while (nw<xx)
	{
		ans++;
		nw+=(a[nw]-nw+1)/2;
	}
	cout<<ans+1<<endl;
	for (int i=0;i<=n;i++) a[i]=0;
		
		
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