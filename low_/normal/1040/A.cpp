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
#define mn 100005
#define FLN "test"

int n, A, B, a[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>A>>B;
	for (int i=1; i<=n; i++) cin>>a[i];
	int ans=0;
	if (n%2==1) if (a[n/2+1]==2) ans=min(A, B);
	for (int i=1; i<=n/2; i++)
	{
		if ((a[i]==0 && a[n+1-i]==1) || (a[i]==1 && a[n+1-i]==0)) 
		{
			ans=-1;
			break;
		}
		else if ((a[i]==0 && a[n+1-i]==2) || (a[i]==2 && a[n+1-i]==0)) ans+=A;
		else if (a[i]+a[n+1-i]==3) ans+=B;
		else if (a[i]+a[n+1-i]==4) ans+=2*min(A, B);
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: