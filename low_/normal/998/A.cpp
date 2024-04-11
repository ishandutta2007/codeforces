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
	
	int n;
	pair <int, int> A[15];
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i].first, A[i].second=i;
	sort(A+1, A+n+1);
	
	if (n==1)
	{
		cout<<-1;
		return 0;
	}
	if (n==2) 
	{
		if (A[1].first==A[2].first) cout<<-1;
		else cout<<"1\n1";
		return 0;
	}
	
	cout<<"1\n"<<A[1].second;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: