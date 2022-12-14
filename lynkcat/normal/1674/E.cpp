// Lynkcat.
// Problem: E. Breaking the Wall
// URL: https://codeforces.com/contest/1674/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

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
#define N 200005
using namespace std;
int a[N],b[N];
int n;
void BellaKira()
{
	IOS;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	int ans=(b[1]+1)/2+(b[2]+1)/2;
	for (int i=1;i<=n;i++) b[i]=a[i];
	for (int i=1;i+1<=n;i++)
		ans=min(ans,max(max((a[i]+1)/2,(a[i+1]+1)/2),(a[i]+a[i+1]+2)/3));
	for (int i=2;i<=n-1;i++)
		ans=min(ans,min(b[i-1],b[i+1])+(max(b[i-1],b[i+1])-min(b[i-1],b[i+1])+1)/2);
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}