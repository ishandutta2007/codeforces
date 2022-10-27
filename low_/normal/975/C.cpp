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

int n, q, A[2*mn], K[2*mn];

int mcdA[2*mn];

int CNP(int u, int l, int r)
{
	if (u>=mcdA[r]) return r+1;
	if (u<mcdA[l]) return l;
	
	int m=(l+r)/2+1;
	
	if (u>=mcdA[m]) return CNP(u, m, r);
	else return CNP(u, l, m-1);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	mcdA[0]=0;
	for (int i=1; i<=n; i++) 
	{
		cin>>A[i];
		mcdA[i]=mcdA[i-1]+A[i];
	}
	
	for (int i=1; i<=q; i++) cin>>K[i];
	
	int Arr=0;
	for (int i=1; i<=q; i++)
	{
		Arr+=K[i];
		int c=CNP(Arr, 1, n);
		
		if (c==n+1)
		{
			Arr=0;
			cout<<n<<"\n";
		}
		else cout<<n-c+1<<"\n";
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: