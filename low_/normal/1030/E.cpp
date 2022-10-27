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
#define mn 300005
#define FLN "test"

int B_ize(int u)
{
	int ret=0, t=u;
	while (t>0)
	{
		ret+=t%2;
		t/=2;
	}
	return ret;
}

int A[mn], B[mn], n;

//DP
int mcd[mn];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>A[i];
		B[i]=B_ize(A[i]);
	}
	
	int od=0, ev=1;
	mcd[0]=0;
	for (int i=1; i<=n; i++) 
	{
		mcd[i]=mcd[i-1]+B[i];
		if (mcd[i]%2==0) ev++;
		else od++;
	}
	
	int ans=(od*(od-1))/2+(ev*(ev-1))/2;
	
//	cerr<<ans<<'\n';
	for (int l=1; l<=n; l++) 
	{
		int ttl=0, _m=B[l];
		for (int r=l; r<=l+61 && r<=n; r++)
		{
			
			ttl+=B[r];
			_m=max(_m, B[r]);
			if (ttl%2==1) continue;
			if (ttl-_m<_m) ans--;
		}
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_