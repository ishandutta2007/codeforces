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
#define inf 200000000000001
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

pii P1, P2;
int n; string S;
pii mcd[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>P1.XX>>P1.YY>>P2.XX>>P2.YY>>n>>S;
	
	S="_"+S;
	mcd[0]={0, 0};
	for (int i=1; i<=n; i++)
	{
		if (S[i]=='U') mcd[i]={mcd[i-1].XX, mcd[i-1].YY+1};
		if (S[i]=='D') mcd[i]={mcd[i-1].XX, mcd[i-1].YY-1};
		if (S[i]=='L') mcd[i]={mcd[i-1].XX-1, mcd[i-1].YY};
		if (S[i]=='R') mcd[i]={mcd[i-1].XX+1, mcd[i-1].YY};
	}
	
	int l=1, r=inf;
	while (r>l)
	{
		int mid=(l+r)/2;
		pii temp=P1;
		int Q=mid/n, R=mid%n;
		temp.XX+=mcd[n].XX*Q; 
		temp.YY+=mcd[n].YY*Q;
		temp.XX+=mcd[R].XX;
		temp.YY+=mcd[R].YY;
		
		
		if (abs(temp.XX-P2.XX)+abs(temp.YY-P2.YY)<=mid) r=mid;
		else l=mid+1;
	}
	
	if (l==inf) cout<<"-1";
	else cout<<l;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/