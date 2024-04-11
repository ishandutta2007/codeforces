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

int n, d, x[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>d;
	for (int i=1; i<=n; i++) cin>>x[i];
	
	sort(x+1, x+n+1);
	
	int ans=2;
	for (int i=1; i<n; i++)
	{
		if (x[i+1]-x[i]>d*2) ans+=2;
		else if (x[i+1]-x[i]==d*2) ans++;
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: