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
#define N 2005
using namespace std;
int n,m,a[N],b[N];
void BellaKira()
{
	cin>>n>>m;
	int mxa=0,mxb=0;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		mxa=max(mxa,a[i]);
		mxb=max(mxb,b[i]);
	}
	if (mxa+mxb>n) cout<<"IMPOSSIBLE"<<endl;
	else
	{
		for (int i=1;i<=mxa;i++) cout<<'R';
		for (int i=1;i<=max(mxb,n-mxa);i++) cout<<'W';
		cout<<endl;
	}
	
		
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