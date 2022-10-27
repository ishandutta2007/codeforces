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
#define inf 9233720368547757
#define mn 200005
#define FLN "test"

int n, d, s[mn], p[mn];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(FLN".inp", "r", stdin);
//	freopen(FLN".out", "w", stdout);
	
	cin>>n>>d;
	for (int i=1; i<=n; i++) cin>>s[i];
	s[0]=inf;
	for (int i=1; i<=n; i++) cin>>p[i];
	
	int ptr=d;
	while (s[ptr-1]<=s[d]+p[1]) ptr--;
	int ptr2=n, ans=ptr;
	while (ptr<=d)
	{
		if (s[ptr]+p[ptr2]>s[d]+p[1]) ans++;
		ptr2--;
		ptr++;
	}
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_