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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, A[105], B;
	vector <int> cuts;
	int ev=0, od=0;
	
	cuts.clear();
	cin>>n>>B;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++)
	{
		if (A[i]%2==0) ev++;
		else od++;
		
		if (i<n && ev==od) cuts.push_back(-abs(A[i]-A[i+1]));
	}
	
	int ans=0;
	sort(cuts.begin(), cuts.end());
	
	while (!cuts.empty())
	{
		if (B+cuts.back()<0) break;
		B+=cuts.back(), ans++;
		cuts.pop_back();
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: