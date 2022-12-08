#include <bits/stdc++.h>

using namespace std;

int d[1005], h[1005];
string s;
int last0;
int last[200005];
signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		cin>>s;
		s='!'+s;
		last0=0;
		for(int i=1; i<s.size(); i++)
		{
			last[i]=last0;
			if(s[i]=='1') last0=i;
		}
		int ans=0;
		for(int i=s.size()-1; i>=1; i--)
		{
			int k=i;
			int sum=0;
			if(s[i]=='1') sum=1, ans++;
			for(int j=1; j<=20; j++)
			{
				k=last[k];
				if(i-k>=20) break;
				sum+=(1<<(i-k));
//				cout<<j<<" "<<sum<<endl;
				if(sum>i) break;
				if(last[k]<=i-sum) ans++;
			}
//			cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}