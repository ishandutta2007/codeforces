#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , a[maxn] , s;
map <LL,priority_queue<LL,vector<LL>,greater<LL> > > mp;
map <LL,priority_queue<LL,vector<LL>,greater<LL> > > ::iterator iter;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
		mp[a[i]].push(i);
	}
	for (iter = mp.begin() ; iter != mp.end() ; iter++)
	{
		while (iter->second.size() >= 2)
		{
			i = iter->second.top();
			iter->second.pop();
			a[i] = 0;
			i = iter->second.top();
			iter->second.pop();
			a[i] *= 2;
			mp[a[i]].push(i);
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] > 0) s++;
	}
	cout << s << "\n";
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] > 0) printf("%I64d ",a[i]);
	}
	return 0;
}