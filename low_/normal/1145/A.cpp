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

int n;
deque <int> A;

bool sorted()
{
	for (int i=1; i<A.size(); i++) if (A[i]<A[i-1]) return 0;
	return 1;
}

int bt(int u)
{
	if (sorted()) return u;
	
	deque <int> w={};
	for (int i=0; i<u/2; i++)
	{
		w.push_front(A.front());
		A.pop_front();
	}
	int ret1=bt(u/2);
	for (int i=0; i<u/2; i++)
	{
		A.push_front(w.front());
		w.pop_front();
	}
	
	for (int i=0; i<u/2; i++)
	{
		w.push_back(A.back());
		A.pop_back();
	}
	int ret2=bt(u/2);
	for (int i=0; i<u/2; i++)
	{
		A.push_back(w.back());
		w.pop_back();
	}
	return max(ret1, ret2);
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
	A.assign(n, 0);
	for (int i=0; i<n; i++) cin>>A[i];
	
	cout<<bt(n);
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/