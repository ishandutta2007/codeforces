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
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int ans=n/100;
	n%=100;
	ans+=n/20;
	n%=20;
	ans+=n/10;
	n%=10;
	ans+=n/5;
	n%=5;
	ans+=n;
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: