#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
signed main()
{
	int t;  cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		cout<<"W";
		for(int i=1;i<m;i++)
			cout<<"B";
		cout<<endl;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<"B";
			cout<<endl;
		}
	}
}