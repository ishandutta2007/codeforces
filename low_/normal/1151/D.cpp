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

pii A[mn];
int n;

bool sort1(pii a, pii b)
{
	if (a.XX==b.XX) return a.YY<b.YY;
	return a.XX>b.XX;
}

bool sort2(pii a, pii b)
{
	return (a.XX-a.YY)>(b.XX-b.YY);
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
	for (int i=1; i<=n; i++) cin>>A[i].XX>>A[i].YY;
	sort(A+1, A+n+1, sort1);
	int ans1=0;
	for (int i=1; i<=n; i++)ans1+=A[i].XX*(i-1)+A[i].YY*(n-i);
	
	sort(A+1, A+n+1, sort2);
	int ans2=0;
	for (int i=1; i<=n; i++)ans2+=A[i].XX*(i-1)+A[i].YY*(n-i);
	cerr<<ans2;
	cout<<min(ans1, ans2);
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/