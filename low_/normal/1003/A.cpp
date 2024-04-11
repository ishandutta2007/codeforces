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
	
	int n, A[105], t;
	cin>>n;
	for (int i=0; i<105; i++) A[i]=0;
	for (int i=0; i<n; i++)
	{
		cin>>t;
		A[t]++;
	}
	
	int ans=0;
	for (int i=0; i<105; i++) ans=max(ans, A[i]);
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: