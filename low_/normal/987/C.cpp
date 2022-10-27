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
#define inf 922337203685477579
#define mn 100005
#define FLN "test"

int n, s[mn], c[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>s[i];
	for (int i=1; i<=n; i++) cin>>c[i];
	
	int ans=inf;
	for (int m=2; m<n; m++)
	{
		int r1=inf, r2=inf;
		for (int i=1; i<m; i++) if (s[i]<s[m]) r1=min(r1, c[i]);
		for (int i=m+1; i<=n; i++) if (s[i]>s[m]) r2=min(r2, c[i]);
		
		if (r1<inf && r2<inf) ans=min(ans, r1+r2+c[m]);
	}
	
	if (ans<inf) cout<<ans;
	else cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: