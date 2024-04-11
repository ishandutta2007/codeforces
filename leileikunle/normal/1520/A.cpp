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
// int a[N];
void solve()
{
	set<char> s;
	int n; cin>>n;
	string a; cin>>a;
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
		{
			if(a[i]!=a[i-1])
			{
				if(s.count(a[i]))
				{
					cout<<"NO"<<endl;
					return;
				}
			}
		}
		if(a[i]!=a[i+1])
		{
			if(s.count(a[i]))
			{
				cout<<"NO"<<endl;
				return;
			}else{
				s.insert(a[i]);
			}
		} 
	}
	cout<<"YES"<<endl;
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