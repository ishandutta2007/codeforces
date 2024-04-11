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
#define mn 505
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int A[mn][mn], B[mn][mn];
int n, m;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>A[i][j];
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>B[i][j];
	
	if (n<2 || m<2)
	{
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) 
			if (A[i][j]!=B[i][j]) {
				cout<<"No";
				return 0;
			}
		
		cout<<"Yes";
		return 0;
	}
	
	for (int i=1; i<=n; i++) {
		int sumRowA=0, sumRowB=0;
		for (int j=1; j<=m; j++) sumRowA+=A[i][j], sumRowB+=B[i][j];
		if ((sumRowA+sumRowB)%2==1) {
			cout<<"No";
			return 0;
		}
	}
	
	for (int j=1; j<=m; j++) {
		int sumColA=0, sumColB=0;
		for (int i=1; i<=n; i++) sumColA+=A[i][j], sumColB+=B[i][j];
		if ((sumColA+sumColB)%2==1) {
			cout<<"No";
			return 0;
		}
	}
	
	cout<<"Yes";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/