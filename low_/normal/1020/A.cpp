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

int n, h, a, b, k;
int ta, fa, tb, fb;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>h>>a>>b>>k;
	
	while (k--)
	{
		cin>>ta>>fa>>tb>>fb;
		
		int ans=abs(ta-tb);
		if (ta==tb) ans+=abs(fa-fb);
		else
		{
			if (fa<a && fb<a) ans+=(a-fa)+(a-fb);
			else if (fa>b && fb>b) ans+=(fa-b)+(fb-b);
			else ans+=abs(fa-fb);
		}
		
		cout<<ans<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: