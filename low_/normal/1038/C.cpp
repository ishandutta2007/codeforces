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

int n;
vector <int> a, b;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i=0; i<n; i++) cin>>a[i];
	for (int i=0; i<n; i++) cin>>b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int pa=0, pb=0;
	
	for (int i=0; i<n; i++)
	{
		//A turn
		if (a.empty()) b.pop_back();
		else if (b.empty()) 
		{
			pa+=a.back();
			a.pop_back();
		}
		else if (a.back()>=b.back())
		{
			pa+=a.back();
			a.pop_back();
		}
		else b.pop_back();
		
		//B turn
		if (b.empty()) a.pop_back();
		else if (a.empty()) 
		{
			pb+=b.back();
			b.pop_back();
		}
		else if (a.back()<=b.back())
		{
			pb+=b.back();
			b.pop_back();
		}
		else a.pop_back();
	}
	
	cout<<pa-pb;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: