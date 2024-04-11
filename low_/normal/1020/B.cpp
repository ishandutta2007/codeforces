#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int n, p[mn];
set <int> ss;

int ans(int u)
{
	if (ss.count(u)==1) return u;
	ss.insert(u);
	return ans(p[u]);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>p[i];
	
	for (int i=1; i<=n; i++)
	{
		ss.clear();
		cout<<ans(i)<<' ';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: