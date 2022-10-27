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

int n, h;
int A[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>h;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	int r=n, l=1;
	while (r>l)
	{
		int mid=(l+r)/2+1;
		vector <int> T={};
		for (int i=1; i<=mid; i++) T.push_back(A[i]);
		
		sort(T.begin(), T.end());
		int H=0;
		for (int i=T.size()-1; i>-1; i-=2) H+=T[i];
		if (H>h) r=mid-1;
		else l=mid;
	}
	cout<<l;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/