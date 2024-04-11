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

map <string, pair <bool, string> > M;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	M.clear();
	M["red"]={1, "Reality"};
	M["blue"]={1, "Space"};
	M["green"]={1, "Time"};
	M["yellow"]={1, "Mind"};
	M["purple"]={1, "Power"};
	M["orange"]={1, "Soul"};
	
	int n;
	string S;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>S;
		M[S].first=0;
	}
	
	cout<<6-n<<"\n";
	for (pair <string, pair <bool, string> > p1:M) if (p1.second.first==1) cout<<p1.second.second<<"\n";
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: