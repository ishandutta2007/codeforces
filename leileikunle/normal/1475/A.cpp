#include <bits/stdc++.h> 
using namespace std;
#define int __int64
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
signed main()
{
	ios; 
	int tt; cin>>tt;
	while(tt--)
	{
		int n; cin>>n;
		int flag = false;
		if(n%2!=0) flag = true;
		else
		{
			while(n%2==0)
			{
				n/=2;
			}
			if(n!=1) flag = true;
		}
		
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}