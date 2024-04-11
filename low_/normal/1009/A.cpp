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

int n, m;
deque <int> B, G;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	B.assign(m, 0);
	G.assign(n+1, 0);
	
	for (int i=1; i<=n; i++) cin>>G[i];
	for (int i=0; i<m; i++) cin>>B[i];
	
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		if (B.empty()) break;
		if (B.front()>=G[i]) B.pop_front(), ans++;
	}
	
	cout<<ans;

}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: