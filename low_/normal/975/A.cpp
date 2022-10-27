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

set <string> ss;
string S, S2;
int n;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	while (n--)
	{
		cin>>S;
		S2="";
		sort(S.begin(), S.end());
		S2.push_back(S[0]);
		for (int i=1; i<S.size(); i++) if (S[i]!=S[i-1]) S2.push_back(S[i]);
		ss.insert(S2);
	}
	
	cout<<ss.size();
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: