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
#define mn 300005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, m, A[mn], P[mn];

int GCD(int u, int v)
{
	if (v==0) return u;
	return GCD(v, u%v);
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=m; i++) cin>>P[i];

	sort(A+1, A+n+1);
	int g=0;
	for (int i=1; i<n; i++) g=GCD(g, A[i+1]-A[i]);
	// cerr<<"GCD "<<g<<"\n";
	int j=inf;
	for (int i=1; i<=m; i++) if (g%P[i]==0) 
	{
		j=i;
		break;
	}
	if (j!=inf)cout<<"YES\n"<<A[1]<<" "<<j<<"\n";
	else cout<<"NO";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/