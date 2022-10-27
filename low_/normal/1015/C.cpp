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

int m, n;
pair <int, int> A[mn];
vector <int> V;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i].first>>A[i].second;
	
	int ttl=0;
	for (int i=1; i<=n; i++) V.push_back(A[i].first-A[i].second), ttl+=A[i].first;
	
	if (ttl<=m) 
	{
	    cout<<0;
	    return 0;
	}
	sort(V.begin(), V.end());
	int ans=0;
	for (int i=V.size()-1; i>=0; i--) 
	{
	    ttl-=V[i];
	    ans++;
	    if (ttl<=m)
	    {
	        cout<<ans;
	        return 0;
	    }
	}
	cout<<-1;
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: