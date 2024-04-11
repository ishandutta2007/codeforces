#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

string s1, s2;
int occ[3][105];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s1>>s2;
	for (int i=0; i<s1.size(); i++) 
	{
		if (s1[i]=='0') occ[1][i]=1; else occ[1][i]=0;
	}
	for (int i=0; i<s2.size(); i++)
	{
		if (s2[i]=='0') occ[2][i]=1; else occ[2][i]=0;
	}
	
	int ans=0, i=0;
	while (i<s1.size()) 
	{
		if (occ[1][i]+occ[2][i]==2)
		{
			if (i>0) if (occ[1][i-1]+occ[2][i-1]==1)
			{
				ans++, i++;
				continue;
			}
			
			cerr<<i<<"\n";
			int l=i, r=i;
			while (r<s1.size())
			{
				if (occ[1][r]+occ[2][r]<2) break;
				r++;
			}
			
			ans+=(r-l)/3*2;
			
			if ((r-l)%3==1 && r<s1.size()) if ((occ[1][r]+occ[2][r])==1) ans++, occ[1][r]=1, occ[2][r]=1;
			if ((r-l)%3==2) ans++;
			
			i=r+1;
		}
		else i++;
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: