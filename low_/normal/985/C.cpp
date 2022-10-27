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

int n, k, l, A[mn];

int CNP(int u, int l, int r)
{
	if (u<A[l]) return l-1;
	if (u>=A[r]) return r;
	
	int m=(l+r)/2;
	
	if (u>=A[m]) return CNP(u, m+1, r);
	else return CNP(u, l, m);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>l;
	
	for (int i=1; i<=n*k; i++) cin>>A[i];
	
	sort(A+1, A+n*k+1);
	
	if (A[n]-A[1]>l) cout<<0;
	else
	{
		int t=0, c=CNP(A[1]+l, 1, n*k);
		int eli=c-n;
		int t1=0;
		for (int i=1; i<=c; i++)
		{
			if (t1==0)
			{
				t1=min(k-1, eli);
				t+=A[i];
				n--;
			}
			else
			{
				eli--;
				t1--;
			}
			
			if (n<=0) break;
		}
		
		cout<<t;
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: