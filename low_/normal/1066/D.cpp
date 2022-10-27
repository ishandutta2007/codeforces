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
	
	int n, m, k;
	int A[mn*2];
	
	signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
//		freopen(FLN".inp", "r", stdin);
//		freopen(FLN".out", "w", stdout);
		
		cin>>n>>m>>k;
		for (int i=n; i>=1; i--) cin>>A[i];
		
		int tempm=m, cur=k;
		for (int i=1; i<=n; i++)
		{
			if (cur<A[i]) 
			{
				tempm--;
				if (tempm==0) 
				{
					cout<<i-1<<'\n';
					return 0;
				}
				cur=k-A[i];
			}
			else cur-=A[i];
		}
		
		cout<<n;
	}
	
	// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
	// Code by low_ 
	// Link: https://codeforces.com/profile/low_