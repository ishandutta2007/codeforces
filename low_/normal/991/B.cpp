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

int n, A[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int S1=0, S0=0;
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>A[i];
		S0+=A[i];
	}
	S1=4*(n/2)+5*(n-n/2);
	sort(A+1, A+n+1);
	
	int d=S1-S0, i=1;
	while (d>0) 
	{
		d-=(5-A[i]);
		i++;
	}
	i--;
	cout<<i;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: