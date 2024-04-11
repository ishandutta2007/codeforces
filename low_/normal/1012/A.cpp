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

int n, a[mn*2];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=0; i<n*2; i++) cin>>a[i];
	
	sort(a, a+(2*n));
	
	int ans, ind=n;
	ans=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
	for (int i=1; i<n; i++) ans=min(ans, (a[i+n-1]-a[i])*(a[2*n-1]-a[0]));
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: