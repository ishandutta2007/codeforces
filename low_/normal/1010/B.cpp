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

int seq[35], cnt, ver;
int m, n, l=0, r;
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>m>>n;
	
	for (int i=1; i<=n; i++)
	{
		cout<<1<<"\n";
		cout<<flush;
		cin>>seq[i];
		if (seq[i]==0) exit(0);
	}
	
	l=1, r=m;
	while (1)
	{
		int mid=(l+r)/2;
		cout<<mid<<"\n";
		cout<<flush;
		cin>>ver;
		ver*=seq[cnt%n+1];
		cnt++;
		if (ver==0) exit(0);
		if (ver==1) l=mid+1;
		else if (ver==-1) r=mid; 
		else exit(0);
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: