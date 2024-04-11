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
#include<ctime>
using namespace std;
#define int long long
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

int n, k;

main()
{	
	cin>>n>>k;
	srand(time(0));
	
	int l=1, r=n;
	string AnS;
	if (k==0)
	{
		while (r>l)
		{
			int mid=(l+r)/2;
			cout<<l<<' '<<mid<<endl;
			
			cin>>AnS;
			
			if (AnS=="Yes") r=mid;
			else l=mid+1;
		}
		
		cout<<l<<' '<<r<<endl;
		exit(0);
	}
	else while (1)
	{
		int mid=(l+r)/2;
		cout<<l<<" "<<mid<<endl;
		
		cin>>AnS;
		
		if (AnS=="Yes") l=max((int)1, l-k), r=min(n, mid+k);
		else l=max((int)1, mid+1-k), r=min(n, r+k);
		
		if (r-l<=4*k+2) //WILD GUESS
		{
			int g=l+rand()%(r-l+1);
			cout<<g<<' '<<g<<endl;
			cin>>AnS;
			if (AnS=="Yes") exit(0);
			else l=max((int)1, l-k), r=min(n, r+k);
		}
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: