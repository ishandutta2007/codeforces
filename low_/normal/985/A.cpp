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

int n, A[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=0; 2*i<n; i++) cin>>A[i];
	
	sort(A, A+(n/2));
	
	int ans=inf, t=0;
	
	for (int i=0; 2*i<n; i++) t+=abs(2*i+1-A[i]);
	ans=min(ans, t);
	t=0;
	for (int i=0; 2*i<n; i++) t+=abs(2*i+2-A[i]);
	ans=min(ans, t);
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: