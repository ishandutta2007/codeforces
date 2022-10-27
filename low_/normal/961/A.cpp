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
	
	int m, n, t;
	cin>>n>>m;
	int A[1005];
	for (int i=1; i<=n; i++) A[i]=0;
	int ans=inf;
	
	while (m--)
	{
		cin>>t;
		A[t]++;
	}
	for (int i=1; i<=n; i++) ans=min(ans, A[i]);
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: