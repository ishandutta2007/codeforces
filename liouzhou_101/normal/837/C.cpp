#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree T;
*/

const int MAXN = 110;

int n, a, b;
int x[MAXN], y[MAXN];

bool check(int x1, int y1, int x2, int y2)
{
	if (x1+x2 <= a && max(y1, y2) <= b)
		return true;
	if (y1+y2 <= b && max(x1, x2) <= a)
		return true;
	return false;
}

int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++ i)
		cin >> x[i] >> y[i];
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = i+1; j <= n; ++ j)
		{
			if (check(x[i], y[i], x[j], y[j])) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
			if (check(x[i], y[i], y[j], x[j])) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
			if (check(y[i], x[i], x[j], y[j])) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
			if (check(y[i], x[i], y[j], x[j])) ans = max(ans, x[i]*y[i]+x[j]*y[j]);
		}
	cout << ans << endl;
	
	return 0;
}