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

int n, a[mn], x;
set <int> ss;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>x;
	for (int i=1; i<=n; i++) cin>>a[i];
	
	ss.clear();
	for (int i=1; i<=n; i++)
	{
		if (ss.count(a[i])==1) 
		{
			cout<<0;
			return 0;
		}
		ss.insert(a[i]);
	}
	
	ss.clear();
	for (int i=1; i<=n; i++) ss.insert(a[i]);
	for (int i=1; i<=n; i++) 
	{
		ss.erase(a[i]);
		if (ss.count(a[i]&x)==1)
		{
			cout<<1;
			return 0;
		}
		ss.insert(a[i]);
	}
	
	ss.clear();
	for (int i=1; i<=n; i++)
	{
		if (ss.count(a[i]&x)==1)
		{
			cout<<2;
			return 0;
		}
		ss.insert(a[i]&x);
	}
	
	cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: