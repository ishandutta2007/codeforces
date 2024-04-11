#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define For(i,a,b) for (int i = a; i <= b; i++)
#define FFOR(i,a,b) for (int i = a; i >= b; i--)
const int ma = 1e5+10;
using namespace std;
int a[ma];
void solve()
{
	int n; cin>>n;
	int sum = 0;
	for(int i=3;i<n;i+=2)
	{
		if(i*i/2+1<=n)
			sum++;
		else break;
	}
	cout<<sum<<'\n';
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