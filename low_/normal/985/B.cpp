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

vector <int> sw[2005];
int cnt[2005];
int m, n;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	char t;
	for (int j=0; j<m; j++) cnt[j]=0;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++)
	{
		cin>>t;
		if (t=='1') sw[i].push_back(j), cnt[j]++;
	}
	
	for (int i=0; i<n; i++)
	{
		bool b=1;
		for (int j=0; j<sw[i].size(); j++) if (cnt[sw[i][j]]==1) b=0;
		if (b)
		{
			cout<<"YES";
			return 0;
		}
	}
	
	cout<<"NO";
	return 0;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: