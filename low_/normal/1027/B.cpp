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

int n, q, x, y;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	while (q--)
	{
		cin>>x>>y;
		int ans=((x+y)%2==0) ? 0 : (n*n)/2+n%2;
		
		if (x%2==0) y+=n;
		x=(x+1)/2;
		y=(y+1)/2;
		ans+=(x-1)*n+y;
		cout<<ans<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: