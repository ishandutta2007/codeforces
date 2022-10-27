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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s1, s2;
	cin>>s1>>s2;
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	
	int i=0;
	while (i<s1.size() && i<s2.size())
	{
		if (s1[i]!=s2[i]) break;
		i++;
	}
	cout<<s1.size()+s2.size()-i*2;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: