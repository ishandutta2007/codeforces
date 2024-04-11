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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int x, y;
	cin>>x>>y;
	
	if (x==y) cout<<'=';
	else if (x==1) cout<<'<';
	else if (y==1) cout<<'>';
	else if (x==2)
	{
		if (y==3) cout<<'<';
		else if (y==4) cout<<'=';
		else cout<<'>';
	}
	else if (y==2)
	{
		if (x==3) cout<<'>';
		else if (x==4) cout<<'=';
		else cout<<'<';
	}
	else if (x>y) cout<<'<';
	else cout<<'>';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: