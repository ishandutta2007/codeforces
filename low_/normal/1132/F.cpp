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
#define mn 1005
#define inf 444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

string S, T;
int n;
int nxt[mn];
int dpret[mn][mn];
int dp(int l, int r)
{
	
	if (l>mn || r>mn) return inf;
	if (dpret[l][r]!=-1) return dpret[l][r];
	if (r<l) return 0;
	if (r==l) return 1;
	
	
	dpret[l][r]=dp(l+1, r)+1;
	for (int i=l+1; i<=r; i++) if (S[i]==S[l]) 
		dpret[l][r]=min(dp(i, r)+dp(l+1, i-1), dpret[l][r]);
	return dpret[l][r];
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
	
	for (int i=0; i<mn; i++) for (int j=0; j<mn; j++) dpret[i][j]=-1;
	
	cin>>n;
	cin>>S;
	T.push_back(S[0]);
	for (int i=1; i<n; i++) if (S[i]!=S[i-1]) T.push_back(S[i]);
	
	
//	cerr<<T<<"\n";
	S=T;
	n=S.size();
	
	for (int i=0; i<n; i++) 
	{
		nxt[i]=inf;
		for (int j=i+1; j<n; j++) if (S[j]==S[i])
		{
			nxt[i]=j;
			break;
		}
	
	}
	cout<<dp(0, n-1);
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/