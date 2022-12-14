#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 60;
int a[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int flag = 1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) flag = 0;
	}
	if(flag)
	{
		cout<<0<<endl;
		return;
	}
	if(a[1]==1||a[n]==n)
	{
		cout<<1<<endl;
		return;
	}
	if(a[1]==n&&a[n]==1)
	{
		cout<<3<<endl;
		return;
	}
	cout<<2<<endl;
	
	
}
signed main()
{
	ios;
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}


}