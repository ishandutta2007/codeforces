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
#define inf 2000000005
#define mn 100005
#define FLN "test"

int n, k, a[mn];
int ttl, E;
vector <int> ans;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) 
	{
		cin>>a[i];
		ttl+=a[i];
	}
	
	if (ttl%k!=0)
	{
		cout<<"No";
		return 0;
	}
	
	E=ttl/k;
	
	int t=0, cnt=0;
	for (int i=1; i<=n; i++)
	{
		t+=a[i], cnt++;
		if (t==E)
		{
			ans.push_back(cnt);
			t=cnt=0;
		}
		else if (t>E)
		{
			cout<<"No";
			return 0;
		}
	}
	
	cout<<"Yes\n";
	for (int i:ans) cout<<i<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_