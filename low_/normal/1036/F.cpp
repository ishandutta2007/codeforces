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

int T, n;
int MH[63]={0, 0, 1000000000, 1000000, 31622, 3981, 1000, 372, 177, 100, 63, 43, 31, 24, 19, 15, 13, 11, 10, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1};
int MH2[63]={0, 0, 1, 1, 0, 1, -1, 1, 0, 0, -1, 1, 0, 1, -1, -1, 0, 1, 0, 1, 0, -1, -1, 1, 0, 0, -1, 0, 0, 1, 1, 1, 0, -1, -1, -1, 0, 1, -1, -1, 0, 1, 1, 1, 0, 0, -1, 1, 0, 0, 0, -1, 0, 1, 0, -1, 0, -1, -1, 1, 0, 1, -1};

int POW(int tp, int up)
{
	if (up==0) return 1;
	
	int mid=POW(tp, up/2);
	if (up%2==0) return mid*mid;
	else return mid*mid*tp;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while (T--)
	{
		cin>>n;
		int ans=n-1;
		for (int i=2; i<60; i++)
		{
			int l=1, r=MH[i];
			while (r>l)
			{
		//		cerr<<i<<" "<<r<<' '<<l<<'\n';
				int mid=(r+l)/2+1;
				
				if (POW(mid, i)>n) r=mid-1;
				else l=mid;
			}
			
			ans-=(l-1)*MH2[i];
		}
		
		cout<<ans<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: