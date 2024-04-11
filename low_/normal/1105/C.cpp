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
#define mod 1000000007
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, r, l;
int dpret[mn][3];
int C[3];

int dp(int i, int rem)
{
//	cerr<<i<<" "<<rem<<"\n";
	if (dpret[i][rem]!=-inf) return dpret[i][rem];
	if (i==0) return (rem==0);
	dpret[i][rem]=0;
	for (int k=0; k<3; k++) dpret[i][rem]+=dp(i-1, (rem-k+3)%3)*C[k];

	dpret[i][rem]%=mod;
	return dpret[i][rem];
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i=0; i<mn; i++) for (int j=0; j<3; j++) dpret[i][j]=-inf;
	cin>>n>>l>>r;
	C[0]=C[1]=C[2]=(r-l+1)/3;
	if ((r-l)%3==0) C[r%3]++;
	else if ((r-l)%3==1) C[r%3]++, C[l%3]++;
	cerr<<C[0]<<' '<<C[1]<<' '<<C[2]<<'\n';
	cout<<dp(n, 0);
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/