#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
signed main()
{
	ios; 
	int tt; cin>>tt;
	while(tt--)
	{
		int n; cin>>n;
		int flag = 1;
		if(n<2020) flag = false;
		else{
			int t = n/2020;
			int f = n%2020;
			if(t<f) flag = false;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}