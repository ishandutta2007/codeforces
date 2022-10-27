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

vector <pair <int, int> > dq;
int n;

bool sort2(pair <int, int> a, pair <int, int> b)
{
	return a.second>b.second;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	dq.assign(n, {0, 0});
	for (int i=0; i<n; i++) cin>>dq[i].first>>dq[i].second;
	
	int ans=0, l, r;
	
	sort(dq.begin(), dq.end());
	l=-1, r=inf;
	for (int i=0; i<n-1; i++)
	{
		l=max(l, dq[i].first);
		r=min(r, dq[i].second);
	}
	ans=max(ans, r-l);
	
	sort(dq.begin(), dq.end(), sort2);
	l=-1, r=inf;
	for (int i=0; i<n-1; i++)
	{
		l=max(l, dq[i].first);
		r=min(r, dq[i].second);
	}
	ans=max(ans, r-l);
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: