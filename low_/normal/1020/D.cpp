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

int n;

main()
{
//	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	if (n%4==2) 
	{
		cout<<"! -1"<<endl;
		exit(0);
	}
	
	int f1, f2, v1, v2;
	cout<<"? 1"<<endl;
	cin>>f1;
	cout<<"? "<<n/2+1<<endl;
	cin>>f2;
	
	if (f1==f2) 
	{
		cout<<"! 1"<<endl;
		exit(0);
	}
	
	int l=1, r=n/2;
	while (r>l)
	{
		int mid=(l+r+1)/2;
		cout<<"? "<<mid<<endl;
		cin>>v1;
		cout<<"? "<<mid+n/2<<endl;
		cin>>v2;
		if ((f1-f2)*(v1-v2)>=0) l=mid;
		else r=mid-1;
	}
	cout<<"! "<<l<<endl;
	exit(0);
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: