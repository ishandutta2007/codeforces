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

int n, m, k;
pii A[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) cin>>A[i].XX, A[i].YY=i;
	sort(A+1, A+n+1);
	
	vector <int> V1={};
	int ans=0;
	for (int i=n-m*k+1; i<=n; i++) V1.push_back(A[i].YY), ans+=A[i].XX;
	sort(V1.begin(), V1.end());
	
	cout<<ans<<"\n";
	for (int i=m-1; i<V1.size()-1; i+=m) cout<<V1[i]<<" ";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/