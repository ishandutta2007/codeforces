#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 2e5+10;

void solve()
{
	int k; cin>>k;
	if(k==100)
	{
		cout<<1<<endl;
		return;
	}else{
		int t = 100-k;
		cout<<t/__gcd(k,t)+k/__gcd(k,t)<<endl;
	}
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