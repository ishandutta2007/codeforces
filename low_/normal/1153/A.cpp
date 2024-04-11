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

int n, t;
int s[mn], d[mn];
int m[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>t;
	for (int i=1; i<=n; i++) cin>>s[i]>>d[i];
	
	int ans=0;
	m[0]=inf;
	for (int i=1; i<=n; i++)
	{
		m[i]=s[i];
		while (m[i]<t) m[i]+=d[i];
		if (m[i]<m[ans]) ans=i;
	//	cerr<<m[i]<<"\n";
	}
	cout<<ans;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/