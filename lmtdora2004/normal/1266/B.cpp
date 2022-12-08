#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		int cac;
		cin>>cac;
		bool flag=false;
		for(int i=1; i<=6; i++)
		{
			if((cac-21+i)%14==0&&(cac-21+i)>=0) flag=true;
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
}