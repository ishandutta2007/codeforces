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
#define mod 998244353 
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, A[mn*2];
int mx[mn*2];
map <int, int> MAP;

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
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=n; i>0; i--)
	{
		if (MAP.count(A[i])==0) mx[i]=MAP[A[i]]=i;
		else mx[i]=MAP[A[i]];
	}
	
	int p1=1, p2;
	int t1=-1;
	while (p1<=n)
	{
		p2=mx[p1];
		while (p1<=p2)
		{
			p2=max(p2, mx[p1]);
			p1++;
		}
		t1++;
	}
	
	int ans=1;
	for (int i=0; i<t1; i++) ans=(ans*2)%mod;
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/