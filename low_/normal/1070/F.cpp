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
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"

deque <int> V00, V01, V10, V11;
int n, x;
string s;

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
	for (int i=1; i<=n; i++) 
	{
		cin>>s>>x;
		if (s=="00") V00.push_back(x);
		else if (s=="01") V01.push_back(x);
		else if (s=="10") V10.push_back(x);
		else V11.push_back(x);
	}
	
//	sort(V00.begin(), V00.end());
	sort(V01.begin(), V01.end());
	sort(V10.begin(), V10.end());
	
	int ttl=0, ans=0;
	while (!V11.empty())
	{
		ans+=V11.back(), ttl++;
		V11.pop_back();
	}
//	cerr<<ans<<'\n';
	int m=min(V01.size(), V10.size());
	for (int i=0; i<m; i++)
	{
		ans+=V01.back()+V10.back(), ttl+=2;
		V01.pop_back(), V10.pop_back();
	}
//	cerr<<ans<<'\n';
	while (!V01.empty())
	{
		V00.push_back(V01.back());
		V01.pop_back();
	}
	
	while (!V10.empty())
	{
		V00.push_back(V10.back());
		V10.pop_back();
	}
	
	sort(V00.begin(), V00.end());
	while (!V00.empty())
	{
		if (2*m>=ttl) break;
		m++, ttl++, ans+=V00.back();
		V00.pop_back();
//		cerr<<ans<<'\n';
	}
	
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/