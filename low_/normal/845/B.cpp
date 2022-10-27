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

bool check_num(int x)
{
	int t1=0, t2=0;
	for (int i=0; i<3; i++)
	{
		t1+=x%10;
		x/=10;
	}
	for (int i=0; i<3; i++)
	{
		t2+=x%10;
		x/=10;
	}
	return (t1==t2);
}

int change_cnt(int u, int v)
{
	int ret=0;
	for (int i=0; i<6; i++){
		ret+=(u%10!=v%10);
		u/=10, v/=10;
	}
	return ret;
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans=inf;
	string S;
	int u=0;
	cin>>S;
	for (int i=0; i<6; i++) u=u*10+S[i]-'0';
	for (int i=0; i<1000000; i++) if (check_num(i)) ans=min(ans, change_cnt(u, i));
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/