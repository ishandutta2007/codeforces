#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		char a[2000];
		cin>>a;
		if(strlen(a) %2 != 0)
		{
			cout<<"NO"<<endl;
		}else if(a[0]==')' || a[strlen(a)-1] == '(')
			cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
		}
	}
	
}