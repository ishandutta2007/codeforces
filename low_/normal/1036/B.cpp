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

int q, n, m, k;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>q;
	while (q--)
	{
		cin>>n>>m>>k;
		int ans=0;
		if (max(m, n)>k) cout<<"-1\n";
		else
		{
			if ((max(m, n)-min(m, n))%2==1) cout<<k-1<<'\n';
			else if ((k-m)%2==1) cout<<k-2<<'\n';
			else cout<<k<<'\n';
		}
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: