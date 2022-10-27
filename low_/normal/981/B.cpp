#include<iostream>
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

map <int, int> MAP;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, u, v;
	cin>>n;
	while (n--) 
	{
		cin>>u>>v;
		MAP[u]=v;
	}
	
	cin>>n;
	while (n--)
	{
		cin>>u>>v;
		if (MAP.count(u)==0) MAP[u]=v;
		else MAP[u]=max(MAP[u], v);
	}
	
	int ans=0;
	for (pair <int, int> p: MAP) ans+=p.second;
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: