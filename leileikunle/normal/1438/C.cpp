#pragma GCC target("avx2,fma")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
int a[105][105];
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if((i+j)%2==1 && a[i][j]%2==0) a[i][j]++;
			else if((i+j)%2==0 && a[i][j]%2==1) a[i][j]++;
			cout<<a[i][j]<<" ";
		}cout<<endl;
	} 
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