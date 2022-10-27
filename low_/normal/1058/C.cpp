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

int n; string s;
vector <int> a;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s;
	for (int i=0; i<n; i++) a.push_back(s[i]-'0');
	int ttl=0;
	for (int i: a) ttl+=i;
	
	if (ttl==0)
	{
		cout<<"YES";
		return 0;
	}
	
	for (int i=1; i<ttl; i++) if (ttl%i==0)
	{
		int cur=0, d=1;
		for (int j:a)
		{
			cur+=j;
			
			if (cur==i) cur=0;
			else if (cur>i) 
			{
				d=0;
				break;
			}
		}
		
		if (d==1) 
		{
			cout<<"YES";
			return 0;
		}
	}
	
	cout<<"NO";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_