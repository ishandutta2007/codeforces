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
//#define int long long
#define mn 100005
#define inf 222222222
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

string A="";
int n;

int compr(string A, string B)
{
	int ret=0;
	for (int i=0; i<min(A.size(), B.size()); i++)
	{
		ret+=min((A[i]-B[i]+26)%26, (B[i]-A[i]+26)%26);
	}
	return ret;
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n; char u;
	for (int i=0; i<n; i++)
	{
		cin>>u;
		A.push_back(u);
	}
	int ans=inf;
	
	for (int i=0; i<=n-4; i++) 
	{
		ans=min(ans, compr(A.substr(i, 4), "ACTG"));
	//	cerr<<A.substr(i, 4)<<" "<<compr(A.substr(i, 4), "ACTG")<<"\n";
	}
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/