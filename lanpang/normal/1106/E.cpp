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
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , m , k , s , t;
LL dp[maxn][210];
struct mmp{
	LL w;
	int d;
	bool operator < (const mmp &op) const{
		if (w == op.w) return d > op.d;
		else return w > op.w;
	}
}p[maxn] , x;
multiset<mmp> st;
vector<int> v[maxn] , vv[maxn];

int main()
{
	int i , j;
	cin >> n >> m >> k;
	for (i = 1 ; i <= k ; i++)
	{
		scanf("%d%d%d%I64d",&s,&t,&p[i].d,&p[i].w);
		v[t].push_back(i);
		vv[s].push_back(i);
	}
	for (i = n ; i >= 1 ; i--)
	{
		for (auto j: v[i])
			st.insert(p[j]);
		if (st.empty())
		{
			for (j = 0 ; j <= m ; j++) 
				dp[i][j] = dp[i+1][j];
			continue;
		}
		x = (*st.begin());
		for (j = 0 ; j <= m ; j++) 
			dp[i][j] = dp[x.d+1][j]+x.w;
		for (j = 1 ; j <= m ; j++)
			dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
		for (auto j: vv[i])
			st.erase(st.find(p[j]));
	}
	cout << dp[1][m] << "\n";
	return 0;
}