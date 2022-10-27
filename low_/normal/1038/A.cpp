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

int cnt[30];
int n, k;
string s;
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i=0; i<30; i++) cnt[i]=0;
	
	cin>>n>>k>>s;
	for (int i=0; i<s.size(); i++) cnt[s[i]-'A']++;
	int ans=n;
	for (int i=0; i<k; i++) ans=min(ans, cnt[i]);
	cout<<ans*k;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: