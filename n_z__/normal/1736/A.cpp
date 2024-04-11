#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0,ans2=0;
		vector<int>vv(n+1);
		for(int x=1;x<=n;x++)
		{
			char ch;
			cin>>ch;
			ans+=ch-'0';
			vv[x]=ch;
		}
		for(int x=1;x<=n;x++)
		{
			char ch;
			cin>>ch;
			ans-=ch-'0';
			ans2+=(vv[x]!=ch);
		}
		cout<<min(abs(ans)+1,ans2)<<endl;
	}
}