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

int n, C[mn];

vector <int> V={0};
int dpret[5005][5005];

int dp(int l, int r)
{
	if (r<=l) return 0;
	if (dpret[l][r]>-1) return dpret[l][r];
	
	if (V[l]==V[r]) return dpret[l][r]=dp(l+1, r-1)+1;
	else return dpret[l][r]=min(dp(l+1, r)+1, dp(l, r-1)+1);
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
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>C[i];
	for (int i=1; i<=n; i++) if (C[i]!=V.back()) V.push_back(C[i]);
	
	n=V.size()-1;
	
	for (int i=0; i<5005; i++) for (int j=0; j<5005; j++) dpret[i][j]=-1;
	
	cout<<dp(1, n);
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/