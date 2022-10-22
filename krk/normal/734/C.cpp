#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 200005;

int n, m, k;
int x, s;
int a[Maxm], b[Maxm];
int c[Maxm], d[Maxm];
ll res;

ll Solve(ll x, ll lft)
{
	int ind = upper_bound(d, d + k, lft) - d - 1;
	ll nd = n - (ind >= 0? c[ind]: 0);
	return nd > 0? nd * x: 0;
}

int main() 
{
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &x, &s);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < k; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < k; i++)
		scanf("%d", &d[i]);
	res = Solve(x, s);
	for (int i = 0; i < m; i++)
		if (b[i] <= s) res = min(res, Solve(a[i], s - b[i]));
	cout << res << endl;
    return 0;
}