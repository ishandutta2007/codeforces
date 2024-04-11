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

int n, A[mn];
signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];

	int ans=inf, anst=0;;
	for (int t=1; t<=100; t++)
	{
		int ret=0;
		for (int i=1; i<=n; i++) 
			ret+=min(abs(A[i]-t), min(abs(A[i]-(t-1)), abs(A[i]-(t+1))));
		if (ret<ans) ans=ret, anst=t;
	}
	cout<<anst<<" "<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/