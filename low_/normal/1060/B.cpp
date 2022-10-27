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

int S(int k)
{
	int t=k, ret=0;
	while (t>0)
	{
		ret+=t%10;
		t/=10;
	}
	return ret;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	int cnt1=0, sn=0, t=n;
	while (t>0)
	{
		cnt1++, sn+=t%10;
		t/=10;
	}
	
	for (int i=0; i<cnt1-1; i++) t=t*10+9;
	sn=n-t;
	
	cout<<S(sn)+S(t);
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_