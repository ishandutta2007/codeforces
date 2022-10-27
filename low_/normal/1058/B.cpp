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
#define point pair <int, int> 
#define X first
#define Y second

bool CCW(point A, point B, point C)
{
	int ret=(C.X-B.X)*(B.Y-A.Y)-(B.X-A.X)*(C.Y-B.Y);
	cerr<<A.X<<' '<<A.Y<<' '<<B.X<<' '<<B.Y<<' '<<C.X<<' '<<C.Y<<' '<<ret<<'\n';
	return (ret<=0);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, q, x, y;
	cin>>n>>k;
	point a={0, k}, b={k, 0}, c={n, n-k}, d={n-k, n};
	point t;
	cin>>q;
	while (q--)
	{
		cin>>t.X>>t.Y;
		if (!CCW(t, a, b) || !CCW(t, b, c) || !CCW(t, c, d) || !CCW(t, d, a)) cout<<"NO\n";
		else cout<<"YES\n";
	}
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_