#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		if(n==1) cout<<9<<endl;
		else if(n==2) cout<<98<<endl;
		else if(n==3) cout<<989<<endl;
		else{
			int m = n-3;
			int b[11] = {9,0,1,2,3,4,5,6,7,8,9};
			cout<<989;
			for(int i=1;i<=m;i++)
			{
				cout<<b[i%10];
			}
			cout<<endl;
		}
		
	}
 }