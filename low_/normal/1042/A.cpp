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

int m, n, A[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int ttl=m, M=-1;
	for (int i=1; i<=n; i++) 
	{
		cin>>A[i];
		ttl+=A[i], M=max(M, A[i]);
	}
	
	cout<<max(ttl/n+((ttl%n)>0), M)<<' '<<M+m;
	
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_