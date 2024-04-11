#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k; cin>>n>>k;
	string s; cin>>s;
	if(n<=2*k)
	{
		cout<<"NO"<<endl;
	}else{
		int t = s.size();
		for(int i=0,j=n-1;i<k;i++,j--)
		{
			if(s[i]!=s[j])
			{
				cout<<"NO"<<endl;
				return;
			}
		}
		cout<<"YES"<<endl;
	}
}
int main()
{
	int tt; cin>>tt;
	while(tt--)
	{
		solve();
	}
}