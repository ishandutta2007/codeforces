#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using namespace std;

const int N = 2e5+10;
int a[N];
map<int,int> mp; 
void solve()
{
	int n; cin>>n;
	mp.clear();
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans += (mp[a[i]-i]);
		mp[a[i]-i]++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios;
	int tt = 1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
}