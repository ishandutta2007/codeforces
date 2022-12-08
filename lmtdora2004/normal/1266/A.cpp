#include <bits/stdc++.h>

using namespace std;

signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		string s;
		cin>>s;
		int cnt0=0, sm=0, cnt2=0;
		for(auto i:s)
		{
			int ok=i-'0';
			sm+=ok;
			if(ok==0) cnt0++;
			if(ok%2==0) cnt2++;
		}
		if(sm%3==0&&cnt2>1&&cnt0>=1) cout<<"red\n";
		else cout<<"cyan\n";
	}
}