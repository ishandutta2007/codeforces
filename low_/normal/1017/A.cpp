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

pair <pair <int, int>, pair <pair <int, int>, pair <int, int> > > A[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>A[i].second.first.first>>A[i].second.first.second>>A[i].second.second.first>>A[i].second.second.second;
		A[i].first.first=A[i].second.first.first+A[i].second.first.second+A[i].second.second.first+A[i].second.second.second;
		A[i].first.second=-i;
	}
	
	sort(A+1, A+n+1);
	
	for (int i=1; i<=n; i++) if (A[i].first.second==-1)
	{
		cout<<n-i+1<<'\n';
		return 0;
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: