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

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a, b, c;
	cin>>c>>b;
	if (c<b)
	{
		b=b+c;
		c=b-c;
		b=b-c;
	}
	
	cin>>a;
	if (c<a)
	{
		a=a+c;
		c=a-c;
		a=a-c;
	}
	
	cout<<max((int)0, c+1-a-b);
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_