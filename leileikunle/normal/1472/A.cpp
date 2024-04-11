#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int a,b,c; cin>>a>>b>>c;
		int sum = 1;
		while(a%2==0)
		{
			sum = sum * 2;
			a/=2;
		}
		while(b%2==0)
		{
			sum = sum * 2;
			b/=2;
		}
		if(sum>=c) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
 }