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
const int N=2e5+5;
struct s{
	int x,y;
}b[N];
int a[N];
int n;
void solve()
{
	memset(b,0,sizeof b);
    cin>>n;
    for1
    {
    	cin>>a[i];
    	int x = a[i];
    	b[x].x=1;  b[x].y=i;
	}
	int ans=0;
	for1
	{
		for(int j=1;j<=(2*n/a[i]);j++)
		{
			if(j==a[i]) continue;
			if(b[j].x && i+b[j].y==a[i]*j)  ans++;
		}
	}
    cout<<ans/2<<endl;
	
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