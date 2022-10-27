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
	int n;
	cin>>n;
	set <int> S;
	int temp;
	for (int i=0; i<n; i++)
	{
		cin>>temp;
		if (temp>0) S.insert(temp);
	}
	cout<<S.size();
}