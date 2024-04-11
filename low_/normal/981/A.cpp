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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	bool b=1;
	char c=s[0];
	for (int i=0; i<s.size(); i++) if (s[i]!=c) b=0;
	if (b==1) cout<<0;
	else
	{
		b=1;
		for (int i=0; i<s.size(); i++) if (s[i]!=s[s.size()-1-i]) b=0;
		if (b==1) cout<<s.size()-1;
		else cout<<s.size();
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: