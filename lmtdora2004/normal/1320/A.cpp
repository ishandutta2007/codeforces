#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> lmao;

signed main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int x;
		cin>>x;
		lmao[x-i]+=x;
		ans=max(ans, lmao[x-i]);
	}
	cout<<ans;
}