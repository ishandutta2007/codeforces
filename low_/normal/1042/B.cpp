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
#define inf 9223372036854775
#define mn 100005
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, t;
	int A[8];
	for (int i=0; i<8; i++) A[i]=inf;
	map <string, int> MAP={{"ABC", 0}, {"AB", 1}, {"BC", 2}, {"AC", 3}, {"A", 4}, {"B", 5}, {"C", 6}};
	string s;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>t>>s;
		sort(s.begin(), s.end());
		A[MAP[s]]=min(A[MAP[s]], t);
	}
	
	int ans[8]={A[4]+A[5]+A[6], A[4]+A[2], A[5]+A[3], A[6]+A[1], A[1]+A[2], A[2]+A[3], A[3]+A[1], A[0]};
	int p=inf;
	for (int i=0; i<8; i++) p=min(ans[i], p);
	if (p<inf) cout<<p;
	else cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_