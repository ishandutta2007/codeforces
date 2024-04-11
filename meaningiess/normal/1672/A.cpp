#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,ans=0;cin>>n;
		for (i=1;i<=n;i++) {int x;cin>>x;ans+=x-1;}
		if (ans&1) puts("errorgorn");
		else puts("maomao90");
	}
}