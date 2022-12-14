#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define For(i,a,b) for (int i = a; i <= b; i++)
#define FFOR(i,a,b) for (int i = a; i >= b; i--)
const int ma = 1e5+10;
using namespace std;
void solve()
{
	int n,k; cin>>n>>k;
	if(n%2==0)
	{
		if(k%n==0) cout<<n<<'\n';
		else cout<<k%n<<'\n';
	}else{
		if(((k-1)/(n/2)+(k%n))%n==0) cout<<n<<'\n';
		else cout<<((k-1)/(n/2)+(k%n))%n<<'\n';
	}
}
int a[ma];
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		solve();
	}
}