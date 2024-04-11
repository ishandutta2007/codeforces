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
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int k, n, p, s;
	cin>>k>>n>>s>>p;
	int x1=(n/s+(int)(n%s>0))*k;
	cout<<x1/p+(int)(x1%p>0);
}