#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		vector<int> a(4);
		for(int i=0;i<4;i++)
		{
			
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		cout<<a[0]*a[2]<<endl;
	}
	
}