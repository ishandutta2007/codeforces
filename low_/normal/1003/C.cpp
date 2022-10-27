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

int n, k, A[5005];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int temp=0, t2=0, p1, p2;
	double ans=0;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	while (k<=n)
	{
		temp=0;
		for (int i=1; i<=k; i++) temp+=A[i];
		t2=temp, p1=1, p2=k+1;
		while (p2<=n)
		{
			t2+=A[p2]-A[p1];
			temp=max(temp, t2);
			p2++, p1++;
		}
		
		ans=max(ans, (double)temp/(double)k);
		k++;
	}
	
	printf("%0.8f", ans);
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: