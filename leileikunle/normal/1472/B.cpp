#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int a[n+3] = {0};
		int b[4] = {0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}
		if(b[2]%2==0){
			if(b[1]%2==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}else{
			if(b[1]>=2 && b[1]%2==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
 }