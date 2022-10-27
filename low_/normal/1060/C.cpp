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
#define mn 2005
#define FLN "test"

int A[mn], B[mn];
int BestA[mn], BestB[mn];
int n, m, x;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], BestA[i]=inf;
	for (int i=1; i<=m; i++) cin>>B[i], BestB[i]=inf;
	cin>>x;
	
	int f, s;
	for (int i=0; i<n; i++) 
	{
		f=s=0;
		for (int j=i+1; j<=n; j++) 
		{
			f+=A[j], s++;
			BestA[s]=min(BestA[s], f);
		}
	}
	
	for (int i=0; i<m; i++)
	{
		f=s=0;
		for (int j=i+1; j<=m; j++)
		{
			f+=B[j], s++;
			BestB[s]=min(BestB[s], f);
		}
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (BestA[i]*BestB[j]<=x) ans=max(ans, i*j);
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_