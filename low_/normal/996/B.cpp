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
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	int ans=1, M=A[1]/n+(int)((A[1]%n)>0);
	
	for (int i=1; i<=n; i++) if (M>((A[i]-i+1)/n+(int)(((A[i]-i+1)%n)>0))) ans=i, M=(A[i]-i+1)/n+(int)(((A[i]-i+1)%n)>0);
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: