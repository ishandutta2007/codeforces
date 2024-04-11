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
int m, n, a, b;

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>n>>m;
	double ans=1000, e;
	for (int i=0; i<n; i++)
	{
		cin>>a>>b;
		e=(double)a/(double)b;
		ans=min(ans, e);
	}
	ans=ans*m;
	
	printf("%0.8f", ans);
}