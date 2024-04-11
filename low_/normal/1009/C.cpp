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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, x, d;
	cin>>n>>m;
	int Tx=0, Tl=0, Tm=0;
	while (m--)
	{
		cin>>x>>d;
		Tx+=x;
		Tl+=d*(d<0);
		Tm+=d*(d>0);
	}
	
	int ans=0;
	for (int i=1; i<=n; i++) ans+=Tx+Tl*abs((n+1)/2-i)+Tm*(n-i);
	printf("%0.8f", (double)ans/(double)n);
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: