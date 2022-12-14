#pragma GCC target("avx2,fma")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
const int N=1e5+5;
int a[N],b[N],c[N];
int n;
void solve()
{
	cin>>n;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int q = a[n];
	for(int i=2;i<=n;i++)
	{
		int t = a[i]-a[i-1];
		b[i-1] = t;
		c[i-1] = c[i-2]+ t;
	}
	for(int i=0;i<(n-1)/2;i++)
	{
		sum+=c[n-i-1]-c[i];
		ans+=sum;
	}
	ans+=ans;
	if((n-1)&1)  sum+=b[n/2],ans+=sum;
	cout<<q-ans<<endl;
}
signed main()
{
    int tt = 1;
    cin>>tt;
    while(tt--)
    {
        solve();
    }
}