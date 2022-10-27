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
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"
#define eps 1e-9

int m, n, a[1005], b[1005];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++) cin>>b[i];
	b[n+1]=b[1];
	
	double l=0, r=1000000005;
	while (r-l>eps)
	{
		double mid=(double)(r+l)/(double)2, temp;
		bool pass=1;
		for (int i=1; i<=n; i++) 
		{
//			cerr<<mid<<" ";
			temp=(double)(m+mid)/(double)a[i];
			mid-=temp;
//			cerr<<mid<<" ";
			if (mid+eps<0)
			{
				pass=0;
				break;
			}
			temp=(double)(m+mid)/(double)b[i+1];
			mid-=temp;
//			cerr<<mid<<" ";
			if (mid+eps<0)
			{
				pass=0;
				break;
			}
		}
		
		if (!pass) l=(double)(r+l)/(double)2+eps;
		else r=(double)(r+l)/(double)2;
	}
	
	if (r<=1000000000)printf("%0.8f", r);
	else cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: