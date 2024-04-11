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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, b, a;
int s[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>b>>a;
	for (int i=1; i<=n; i++) cin>>s[i];
	
	int curB=b, curA=a;
	for (int i=1; i<=n; i++) 
	{
//		cerr<<curB<<' '<<curA<<"\n";
		if (curB==0 && curA==0)
		{
			cout<<i-1;
			return 0;
		}
		
		if (curB==0) curA--;
		else if (curA==a) curA--;
//		else if (curA==0) curB--;
		else if (s[i]==1) curB--, curA++;
		else if (curA==0) curB--;
		else curA--;
	}
	cout<<n;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/