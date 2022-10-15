// Lynkcat.
// Problem: B. Integers Shop
// URL: https://codeforces.com/contest/1621/problem/B
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
#define N 100005
using namespace std;
int n,l[N],r[N],c[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i]>>c[i];
	}
	set<pa>S,S1;
	map<pa,int>Mp;
	for (int i=1;i<=n;i++)
	{
		S.insert(mp(l[i],c[i]));
		S1.insert(mp(r[i],-c[i]));
		if (!Mp.count(mp(l[i],r[i]))) 
			Mp[mp(l[i],r[i])]=c[i];
		else Mp[mp(l[i],r[i])]=min(Mp[mp(l[i],r[i])],c[i]);
		int lx=(*S.begin()).fi;
		int rx=(*S1.rbegin()).fi;
		int nowcst=(*S.begin()).se-(*S1.rbegin()).se;
		// cout<<lx<<" "<<rx<<endl;///
		if (Mp.count(mp(lx,rx))) nowcst=min(nowcst,Mp[mp(lx,rx)]);
		cout<<nowcst<<endl;
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