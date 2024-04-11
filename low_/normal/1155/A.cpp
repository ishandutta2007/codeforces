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

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S;
	int r=0, l=-1;
	int n;
	cin>>n>>S;
	for (int i=0; i<S.size(); i++) 
	{
		if (S[i]<S[r]) {
			l=i;
			break;
		}
		else r=i;
	}
	if (l>-1)cout<<"YES\n"<<r+1<<' '<<l+1;
	else cout<<"NO";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/