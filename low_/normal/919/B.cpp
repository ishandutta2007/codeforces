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

int tcs(int k)
{
	int t=k, ret=0;
	while (t>0)
	{
		ret+=(t%10);
		t=t/10;
	}
	
	return ret;
}

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int cnt=0;
	int i=1;
	vector <int> v;
	while (cnt<10000)
	{
		if (tcs(i)==10)
		{
			cnt++;
			v.push_back(i);
		}
		i++;
	}
	
	int n;
	cin>>n;
	cout<<v[n-1];
}