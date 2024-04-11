#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i;cin>>n;
		ll s=0;
		for (i=1;i<=n;i++)
		{
			int t;cin>>t;
			s+=t;
		}
		if (s%n==0) puts("0");
		else puts("1");
	}
}