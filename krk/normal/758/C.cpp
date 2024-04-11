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

const int Maxn = 105;
const ll Inf = 9000000000000000000ll;

int n, m;
ll k;
int x, y;
ll B[Maxn][Maxn];

void Print()
{
	ll mn = Inf, mx = -Inf;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			mn = min(mn, B[i][j]);
			mx = max(mx, B[i][j]);
		}
	printf("%lld %lld %lld\n", mx, mn, B[x][y]);
}

int Nxt(int i, int &di)
{
	if (i == n && di == 1) { di = -1; return n - 1; }
	if (i == 1 && di == -1) { di = 1; return 2; }
	return i + di;
}

int main() 
{
	cin >> n >> m >> k >> x >> y;
	if (n == 1) {
		ll all = k / m;
		for (int i = 1; i <= k % m; i++)
			B[1][i]++;
		for (int i = 1; i <= m; i++)
			B[1][i] += all;
	} else {
		ll full = k / (m * (2 * n - 2)); k %= (m * (2 * n - 2));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				B[i][j] += (i == 1 || i == n)? full: 2ll * full;
		int di = 1;
		for (int i = 1; i <= n && k > 0; i = Nxt(i, di))
			for (int j = 1; j <= m && k > 0; j++) {
				B[i][j]++; k--;
			}
	}
	Print();
    return 0;
}