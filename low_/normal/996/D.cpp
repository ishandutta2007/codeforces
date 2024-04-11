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
bool passed[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=2*n; i++) cin>>A[i], passed[i]=0;
	int cur, ans=0;
	for (int i=1; i<=2*n; i++) if (passed[A[i]]==0)
	{
		for (int j=i+1; j<=2*n; j++)
		{
			if (A[j]==A[i]) break;
			if (passed[A[j]]==0) ans++;
		}
		passed[A[i]]=1;
	}
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: