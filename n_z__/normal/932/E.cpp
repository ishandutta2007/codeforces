#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int s[5001][5001];
int qp(int o,int k)
{
	if(k>=0)
	{
		int s=1;
		while(k)
		{
			if(k&1)s=s*o%mod;
			o=o*o%mod;
			k/=2;
		}
		return s;
	}
}
signed main()
{
	int n,m;
	cin>>n>>m;
	int o=1,ans=0;
	s[1][1]=1;
	for(int x=2;x<=m;x++)
	for(int y=1;y<=m;y++)
	s[x][y]=(s[x-1][y-1]+s[x-1][y]*y)%mod;
	for(int x=1;x<=m;x++)
	o=o*(n-x+1)%mod,ans=(ans+s[m][x]*o%mod*qp(2,n-x))%mod;
	cout<<ans<<endl;
}