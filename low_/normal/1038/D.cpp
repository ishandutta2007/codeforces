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
#define inf 922337203685477
#define mn 500005
#define FLN "test"

int n, a[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	
	if (n==1)
	{
		cout<<a[1];
		return 0;
	}
	
	bool b=0, c=0; //b if there are negative, c if there are non-neg
	for (int i=1; i<=n; i++) 
	{
		if (a[i]<0) b=1;
		else c=1;
	}
	
	
	if (b && c)
	{
		int ttl=0;
		for (int i=1; i<=n; i++) 
		{
			if (a[i]>0) ttl+=a[i];
			else ttl-=a[i];
		}
		cout<<ttl;
	}
	else if (b)
	{
		int ttl=0, M=-inf;
		for (int i=1; i<=n; i++) ttl-=a[i], M=max(M, a[i]);
		ttl+=2*M;
		cout<<ttl;
	}
	else
	{
		int ttl=0, M=inf;
		for (int i=1; i<=n; i++) ttl+=a[i], M=min(M, a[i]);
		ttl-=2*M;
		cout<<ttl;
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: