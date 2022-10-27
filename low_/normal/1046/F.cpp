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

int N, A[mn*2], x, f;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	for (int i=1; i<=N; i++) cin>>A[i];
	cin>>x>>f;
	
	int q, r;
	int ans=0;
	for (int i=1; i<=N; i++)
	{
		q=A[i]/(x+f);
		r=A[i]%(x+f);
		
		ans+=q*f;
		if (r>x) ans+=f;
	}
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_