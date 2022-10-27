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

int n, a[mn], ans[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	if (a[1]>a[2]) ans[1]=5;
	else if (a[1]==a[2]) ans[1]=3;
	else if (a[1]<a[2]) ans[1]=1;
	for (int i=2; i<=n; i++)
	{
		if (a[i]<a[i+1])
		{
			if (a[i]<=a[i-1]) ans[i]=(ans[i-1]==1) ? 2 : 1;
			else ans[i]=ans[i-1]+1;
		}
		else if (a[i]>a[i+1])
		{
			if (a[i]>=a[i-1]) ans[i]=(ans[i-1]==5) ? 4 : 5;
			else ans[i]=ans[i-1]-1;
		}
		else 
		{
			if (a[i-1]>a[i]) ans[i]=ans[i-1]-1;
			else if (a[i-1]<a[i]) ans[i]=ans[i-1]+1;
			else
			{
				if (ans[i-1]==2) ans[i]=3;
				else ans[i]=2;
			}
		}
	}
	
	
	
	for (int i=1; i<=n; i++) if (ans[i]<1 || ans[i]>5)
	{
		cout<<"-1\n";
		return 0;
	}
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/