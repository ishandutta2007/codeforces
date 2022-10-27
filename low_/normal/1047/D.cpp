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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m, n;
	cin>>m>>n;
	if (m>n)
	{
		m+=n;
		n=m-n;
		m=m-n;
	}
	
	int ans;
	if (m==1)
	{
		ans=n-n%6;
		if (n%6==4) ans+=2;
		else if (n%6==5) ans+=4;
	}
	else if (m==2)
	{
		if (n==2) ans=0;
		else if (n==3 || n==7) ans=m*n-2;
		else ans=m*n;
	}
	else 
	{
		if (m%2==0 || n%2==0) ans=m*n;
		else ans=m*n-1;
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_