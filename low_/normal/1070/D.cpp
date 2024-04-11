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
#define inf 2000000005
#define mn 200005
#define FLN "test"

int n, k, A[mn];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	A[n+1]=0;
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		ans+=A[i]/k;
		A[i+1]+=A[i]%k;
		
		if (A[i]%k!=0)
		{
			A[i+1]=max(A[i+1]-k, (int)0);
			ans++;
		}
	}
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_