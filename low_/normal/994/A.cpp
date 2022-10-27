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
#define FLN "test"

int m, n, A[15];
set <int> ss;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=m; i++) 
	{
		int K;
		cin>>K;
		ss.insert(K);
	}
	
	for (int i=1; i<=n; i++) if (ss.count(A[i])==1) cout<<A[i]<<" ";
	
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: