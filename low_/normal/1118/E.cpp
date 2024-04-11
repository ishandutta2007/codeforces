#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, k;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	vector <pii> ans={};
	
	for (int i=1; i<=k; i++) 
	{
		if (ans.size()>=n) break;
		for (int j=i+1; j<=k; j++)
		{
			if (ans.size()>=n) break;
			ans.push_back({i, j});
			ans.push_back({j, i});
		}
	}
	if (ans.size()<n)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for (int i=0; i<n; i++) cout<<ans[i].XX<<" "<<ans[i].YY<<"\n";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/