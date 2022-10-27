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

int n; string s;
int cnt[100];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s;
	for (int i=0; i<26; i++) cnt[i]=0;
	for (int i=0; i<s.size(); i++) cnt[s[i]-'a']++;
	for (int i=0; i<26; i++) if (cnt[i]>=2 || n==1)
	{
		cout<<"Yes";
		return 0;
	}
	
	cout<<"No";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: