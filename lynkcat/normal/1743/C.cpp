#include<bits/stdc++.h>
using namespace std;
int n;
string st;
void fc()
{
	long long sum=0,val=0;
	cin>>n;
	cin>>st;
	for (int i=1;i<=n;i++)
	{
		long long a=0;
		cin>>a;
		if (st[i-1]=='0')
		{
			val=a;
			continue;
		}
		if (a<val) sum+=val,val=a;
		else sum+=a;
	}
	cout<<sum<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		fc();
	}
}