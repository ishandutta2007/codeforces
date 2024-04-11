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

int n, s, ML[105];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>n>>s;
	int t;
	for (int i=0; i<n; i++) 
	{
		cin>>t>>ML[i];
		ML[i]+=t*60;
	}
	
	if (ML[0]>s) 
	{
		cout<<"0 0";
		return 0;
	}
	
	for (int i=0; i<n-1; i++) if (ML[i]+2*s+1<ML[i+1]) 
	{
		cout<<(ML[i]+s+1)/60<<" "<<(ML[i]+s+1)%60;
		return 0;
	}
	
	cout<<(ML[n-1]+s+1)/60<<" "<<(ML[n-1]+s+1)%60;
}