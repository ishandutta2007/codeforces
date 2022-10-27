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

set <int> ans1, ans2;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int ttl=(n*(n+1))/2;
	int d1=-1, d2=-1;
	for (int i=2; i*i<=ttl; i++) if (ttl%i==0) d1=i, d2=ttl/i;
	
	if (d1==-1)
	{
		cout<<"No";
		return 0;
	}
	
	int ptr=1;
	while (d1>n)
	{
		ans1.insert(ptr);
		d1-=ptr;
		ptr++;
	}
	
	if (d1>0) ans1.insert(d1);
	
	for (int i=1; i<=n; i++) if (ans1.count(i)==0) ans2.insert(i);
	
	cout<<"Yes\n";
	cout<<ans1.size()<<' ';
	for (int i:ans1) cout<<i<<' ';
	cout<<'\n'<<ans2.size()<<' ';
	for (int i:ans2) cout<<i<<' ';

	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: