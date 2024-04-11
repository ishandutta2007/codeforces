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

int n, q, a;
map <int, int> ss;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for (int i=1; i<=n; i++)
	{
		cin>>a;
		ss[a]=i;
	}
	
	if (ss.size()<q) cout<<"NO";
	else
	{
		cout<<"YES\n";
		for (pair <int, int> pii:ss) 
		{
			cout<<pii.second<<' ';
			q--;
			if (q==0) break;
		}
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: