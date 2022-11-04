#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

LL n , k , a[maxn] , ans;
char c[maxn];
priority_queue<LL> pq;

int main()
{
	int i , j;
	cin >> n >> k;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	scanf("%s",c+1);
	ans += a[1];
	pq.push(-a[1]);
	for (i = 2 ; i <= n ; i++)
	{
		ans += a[i];
		if (c[i] != c[i-1]) 
		{
			while (pq.size() > k)
			{
				ans += pq.top();
				pq.pop();
			}
			while (!pq.empty()) pq.pop();
		}
		pq.push(-a[i]);
	}
	while (pq.size() > k)
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans << "\n";
	return 0;
}