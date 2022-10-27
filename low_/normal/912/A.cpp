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
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int a, b, c, d, e;
	cin>>a>>b>>c>>d>>e;
	cout<<max(c*2+d-a, (int)0)+max(d+e*3-b, (int)0);
}