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
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"

int n, k, a[mn];

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
	for (int i=1; i<=n; i++) 
	{
		int t;
		cin>>t;
		a[t]++;
	}
	
	int M=0;
	for (int i=1; i<=100; i++) if (a[i]>0) M=max(M, ((a[i]-1)/k+1)*k);
	
	int ans=0;
	for (int i=1; i<=100; i++) if (a[i]>0) ans+=M-a[i];
	cout<<ans;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/