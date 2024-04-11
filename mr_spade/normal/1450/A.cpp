#include<bits/stdc++.h>
using namespace std;
string s;
signed main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		sort(s.begin(),s.end());
		cout<<s<<endl;
	}
	return 0;
}