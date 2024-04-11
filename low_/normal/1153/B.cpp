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

int A[mn], B[mn], H[105][105];
int n, m, h;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>h;
	for (int i=1; i<=m; i++) cin>>A[i];
	for (int j=1; j<=n; j++) cin>>B[j];
	for (int j=1; j<=n; j++) for (int i=1; i<=m; i++) 
	{
		cin>>H[j][i];
	}
	
	for (int j=1; j<=n; j++) for (int i=1; i<=m; i++) if (H[j][i]==1)
	{
		H[j][i]=min(A[i], B[j]);
	}
	
	for (int j=1; j<=n; j++) 
	{
		for (int i=1; i<=m; i++) 
		{
			cout<<H[j][i]<<" ";
		}
		cout<<endl;
	}
	
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/