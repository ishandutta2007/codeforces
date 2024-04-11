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
	
	int n;
	cin>>n;
	int ptr=0;
	while ((ptr+1)*(ptr+1)<=n) ptr++;
	
	vector <int> ans;
	for (int i=1; i<=n; i++) ans.push_back(i);
	reverse(ans.begin(), ans.end());
	for (int i=0; i+ptr<=n; i+=ptr) reverse(ans.begin()+i, ans.begin()+i+ptr);
	
	reverse(ans.begin()+(n-n%ptr), ans.end());
	for (int p:ans) cout<<p<<' ';
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: