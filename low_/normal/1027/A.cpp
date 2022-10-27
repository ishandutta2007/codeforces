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

int n;
string S;
int T;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while (T--)
	{
		cin>>n>>S;
		bool b=1;
		for (int i=0; i<n/2; i++) if (max(S[i], S[n-i-1])-min(S[i], S[n-i-1])!=2 && max(S[i], S[n-i-1])-min(S[i], S[n-i-1])!=0) b=0;
		if (b) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: