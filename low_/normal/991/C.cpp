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
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
//	while (cin>>n)
		int l=1, r=1000000000000000002;
		
		while (r>l)
		{
			int mid=(l+r)/2;
			
			int V=0, P=0, t=n;
			while (t>0)
			{
				V+=min(mid, t);
				t-=min(mid, t);
				P+=t/10;
				t-=t/10;
			}
			
			if (V<P) l=mid+1;
			else r=mid;
		}
		
		cout<<r<<"\n";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: