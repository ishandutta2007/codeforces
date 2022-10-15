// Lynkcat.
// Problem: F. Build a Tree and That Is It
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/F
// Memory Limit: 256 MB
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
// #define N 
using namespace std;
void BellaKira()
{
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	int a=(x+z-y);
	int b=(x+y-z);
	int c=(y+z-x);
	if (a%2==1||b%2==1||c%2==1) return cout<<"NO"<<endl,void();
	a/=2,b/=2,c/=2;
	if (a+b+c>n-1||(a+b==0)||(b+c==0)||(a+c)==0||a<0||b<0||c<0) cout<<"NO"<<endl;
	else
	{
		int rt=0;
		int lst=1;
		int cnt=3;
		if (a==0) rt=1;
		else if (b==0) rt=2;
		else if (c==0) rt=3;
		// cout<<a<<","<<b<<","<<c<<endl;
		cout<<"YES"<<endl;
		for (int i=1;i<a;i++)
		{
			cout<<lst<<" "<<++cnt<<endl;
			lst=cnt;
		}
		if (!rt) rt=++cnt;
		if (a) cout<<lst<<" "<<rt<<endl;
		lst=2;
		for (int i=1;i<b;i++)
		{
			cout<<lst<<" "<<++cnt<<endl;
			lst=cnt;
		}
		if (b) cout<<lst<<" "<<rt<<endl;
		
		lst=3;
		for (int i=1;i<c;i++)
		{
			cout<<lst<<" "<<++cnt<<endl;
			lst=cnt;
		}
		if (c) cout<<lst<<" "<<rt<<endl;
		
		for (int i=1;i<=n-1-a-b-c;i++) cout<<1<<" "<<++cnt<<endl;
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