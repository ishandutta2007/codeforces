#include<iostream>
#include<fstream>
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

int n, k, s;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>s;
	
	if ((n-1)*k<s || s<k)
	{
		cout<<"NO";
		return 0;
	}
	
	vector <int> ans={1};
	for (int i=0; i<k; i++)
	{
		if (k-i-1<=s-(n-1))
		{
			cerr<<"1 ";
			ans.push_back(n+1-ans.back());
			s-=(n-1);
			cerr<<s<<'\n';
		}
//		else if (k-i-1==s)
//		{
//			cerr<<"2 ";
//			if (ans.back()==1) ans.push_back(2);
//			else ans.push_back(ans.back()-1);
//			s--;
//			cerr<<s<<"\n";
//		}
		else
		{
			cerr<<"3 ";
			if (ans.back()>(s-k+i+1))ans.push_back(ans.back()-(s-(k-i-1)));
			else ans.push_back(ans.back()+(s-k+i+1));
			s-=(s-(k-i-1));
			cerr<<s<<'\n';
		}
	}
	
	cout<<"YES\n";
	for (int i=1; i<=k; i++) cout<<ans[i]<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: