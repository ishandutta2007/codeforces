// Lynkcat.
// Problem: E. Singers' Tour
// URL: https://codeforces.com/contest/1618/problem/E
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
#define N 400005
using namespace std;
int n;
int a[N];
int ans[N];
void BellaKira()
{
	cin>>n;
	int mn=inf;
	int tt=0;
	int sum=0;
	deque<int>q;
	for (int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
    ll pairs=n*(n+1)/2;
    if(sum%pairs)
    {
    	cout<<"NO"<<endl;
        return;
    }
    sum/=pairs;
    for (int i=1;i<=n;i++)
    {
        int j=(i==1?n:i-1);
        ll qwq=a[i]-a[j]-sum;
        if(qwq%n||(qwq/n>=0))
	    {
	    	cout<<"NO"<<endl;
	        return;
	    }
        qwq/=n;
        ans[i]=-qwq;
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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