// Author: Little09
// Problem: E1. LCM Sum (easy version)
// Contest: Codeforces Round #813 (Div. 2)
// URL: https://codeforces.com/contest/1712/problem/E1
// Memory Limit: 512 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];
ll lcm(ll x,ll y)
{
	return x*y/__gcd(x,y);
}
ll c[N],d[N];
ll ca2(ll x)
{
	ll tot=0;
	while (x%2==0) x/=2,tot++;
	return tot;
}

void work()
{
	ll l,r,len;
	cin >> l >> r;
	len=r-l+1;
	ll ans=len*(len-1)*(len-2)/6;
	for (int i=l;i<=r;i++)
	{
		//cout << ans << endl;
		//cout << ans << endl;
		int cnt=0;
		ll op=0;
		for (int j=1;j<=sqrt(i);j++)
		{
			if (i%j!=0) continue;
			if (j>=l&&j<i) op++;
			if (j*j!=i&&i/j>=l&&i/j<i) op++;
		}
		ans-=op*(op-1)/2;
		for (int j=1;j<=sqrt(i*2);j++)
		{
			if (i*2%j!=0) continue;
			if (j>=l&&j<i) d[++cnt]=j;
			if (j*j!=2*i&&2*i/j>=l&&2*i/j<i) d[++cnt]=2*i/j;
		}
		for (int j=1;j<=cnt;j++)
		{
			for (int k=j+1;k<=cnt;k++)
			{
				if (d[j]+d[k]>i) ans--;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i=1;i<=200000;i++) c[i]=ca2(i);
	int T;
	cin >> T;
	while (T--) work();
	// for (ll i=1;i<=500;i++)
	// {
		// for (ll j=i+1;j<=500;j++)
		// {
			// for (ll k=j+1;k<=500;k++)
			// {
				// if (lcm(lcm(i,j),k)<i+j+k)
				// {
					// if (lcm(lcm(i,j),k)!=k&&lcm(lcm(i,j),k)!=k*2)cout << i << " " << j << " " << k << endl;
				// }
			// }
		// }
	// }
	return 0;
}