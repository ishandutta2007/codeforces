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
const int maxn = 3e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , tp;
LL m , a[maxn] , b[maxn] , c , q[maxn] , p[maxn] , mi , ans;
multiset<LL> st;

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d%I64d",&a[i],&b[i]);
		ans = max(ans,m-b[i]);
		b[i] = m-b[i]+b[i-1];
		if (i > 1) 
		{
			c = (a[i]-a[i-1])*(a[i]-a[i-1]);
			mi = b[i-2];
			while (tp > 0 && q[tp] <= c)
			{
				mi = min(mi,p[tp]);
				st.erase(st.find(q[tp]+p[tp]));
				tp--;
			}
			q[++tp] = c;
			p[tp] = mi;
			st.insert(q[tp]+p[tp]);
			ans = max(ans,b[i]-(*st.begin()));
		}
	}
	cout << ans << "\n";
	return 0;
}