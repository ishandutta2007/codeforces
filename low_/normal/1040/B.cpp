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
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin>>n>>q;
	deque <int> dq;
	dq.clear();
	int ans1=0;
	while (dq.size()<n)
	{
		for (int i=0; i<q; i++) dq.push_back(0);
		dq.push_back(1);
		for (int i=0; i<q; i++) dq.push_back(0);
		ans1++;
	}
	
	cout<<ans1<<'\n';
	while (dq.size()>n)
	{
		if (dq.back()==1) dq.pop_front();
		else dq.pop_back();
	}
	
	for (int i=0; i<dq.size(); i++) if (dq[i]==1) cout<<i+1<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_
// Link: