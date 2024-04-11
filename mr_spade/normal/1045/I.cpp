#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline") 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,ans;
string s;
int h[N];
unordered_map<int,int> M0,M1;
signed main()
{
	register int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(auto j:s)
			h[i]^=1<<(j-'a');
	}
	for(i=0;i<26;i++)
	{
		M0.clear();M1.clear();
		for(int j=1;j<=n;j++)
			if(h[j]>>i&1)
				M1[h[j]^1<<i]++;
			else
				M0[h[j]]++;
		for(auto j:M0)
			if(M1.find(j.first)!=M1.end())
				ans+=j.second*M1[j.first];
	}
	M0.clear();
	for(i=1;i<=n;i++)
		M0[h[i]]++;
	for(auto j:M0)
		ans+=j.second*(j.second-1)/2;
	cout<<ans<<endl;
	return 0;
}