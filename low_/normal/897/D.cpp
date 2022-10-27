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

int m, n, c;
int t;
int A[1005];

main()
{	
	cin>>n>>m>>c;
	int N=n;
	for (int i=1; i<=n; i++) A[i]=0;
	while (1)
	{
		cin>>t;
		if (t<=c/2)
		{
			for (int i=1; i<=N; i++) 
			{
				if (A[i]==0) 
				{
					cout<<i<<endl;
					A[i]=t;
					n--;
					break;
				}
				else if (A[i]>t)
				{
					cout<<i<<endl;
					A[i]=t;
					break;
				}
			}
		}
		else
		{
			for (int i=N; i>=1; i--)
			{
				if (A[i]==0)
				{
					cout<<i<<endl;
					A[i]=t;
					n--;
					break;
				}
				else if (A[i]<t)
				{
					cout<<i<<endl;
					A[i]=t;
					break;
				}
			}
		}
		
		if (n==0) exit(0);
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_