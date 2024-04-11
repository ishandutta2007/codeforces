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

int A[35], n;

signed main()
{
	int x=1000, l=0, r=1000*1000*1000;
	cin>>n;
	string I;
	int Lcol;
	cout<<x<<' '<<l<<endl;
	cin>>I;
	Lcol= (I=="black");
	for (int i=1; i<n; i++)
	{
		int y=(l+r)/2;
		cout<<x<<' '<<y<<endl;
		cin>>I;
		int Ccol=(I=="black");
		if (Ccol==Lcol) l=y;
		else r=y;
	}
	
	//if (l<r-1) cout<<x<<" "<<l+1<<" "<<x+1<<" "<<l+1<<endl;
	cout<<x-1<<" "<<l<<" "<<x+1<<" "<<r<<endl;
	exit(0);
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_