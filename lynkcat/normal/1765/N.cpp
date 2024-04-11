// Problem: N. Number Reduction
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/N
// Memory Limit: 512 MB
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
#define N 500005
using namespace std;
int s[N][10];
inline int query(int l,int r,int v)
{
	if (v==-1) return 0;
	l++,r++;
	return s[r][v]-s[l-1][v];
}
void BellaKira()
{
	string st,ans;
	int m;
	cin>>st>>m;
	m=st.size()-m;
	int n=st.size();
	for (int i=1;i<=n;i++)
		for (int j=0;j<=9;j++)
			s[i][j]=s[i-1][j]+(st[i-1]-'0'==j);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=9;j++) s[i][j]+=s[i][j-1];
	int l=0;
	for (int i=1;i<=m;i++)
	{
		int pos=l;
		int v=st[pos]-'0';
		int lim=0;
		if (i==1) lim=1;
		// cout<<i<<","<<n-1-(m-i)<<'\n';
		while (l<=n-1-(m-i))
		{
			if (i==1&&v==1) break;
			if (query(l,n-1-(m-i),v-1)-query(l,n-1-(m-i),lim-1)==0) break;
			if (st[l]-'0'<v&&st[l]-'0'>=lim)
			{
				v=st[l]-'0';
				pos=l;
			}
			l++;
		}
		ans+=st[pos];
		l=pos+1;
	}
	cout<<ans<<'\n';
		
		
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