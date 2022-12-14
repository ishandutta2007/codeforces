#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FFOR(i,a,b) for (int i = a; i >= b; i--)
const int ma = 1e2+10;
using namespace std;
int a[ma],b[ma];
void solve()
{
	int n; cin>>n;
	FOR(i,1,n) cin>>a[i];
	int sum = 0;
	sort(a+1,a+n+1);
	FOR(i,1,n-1)
	{
		sum++;
		if(a[i]!=a[i+1])
		{
			break;
		}else if(sum==n-1 && a[n-1]==a[n])
		{
			cout<<0<<'\n';
			return;
		}
		
	}
	cout<<n-sum<<'\n';
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