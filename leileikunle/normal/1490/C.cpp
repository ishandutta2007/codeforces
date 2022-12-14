#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FFOR(i,a,b) for (int i = a; i >= b; i--)
const int ma = 1e5+10;
using namespace std;
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=10000;i++)
	{
		int t = (int)(pow(n-(i*i*i), 1.0/3));
		if(t==0) continue;
		for(int j=t;j<=t+4;j++)
		{
			if(i*i*i+j*j*j>n) break;
			if(i*i*i+j*j*j==n) 
			{
				cout<<"YES"<<'\n';
				return;
			}
		}
	}
	cout<<"NO"<<'\n';
	return;
}
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		solve();
	}
}