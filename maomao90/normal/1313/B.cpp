#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)
#define ALL(arr) arr.begin(), arr.end()
#define mnto(x, y) x = min(x, y)
#define pb emplace_back
#define FI first
#define SE second
typedef pair<int, int> ii;

#define MAXN 100005
#define INF 1000000005

int t;
int n, x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &x, &y);
		int mn = 0, mx = 0;
		if (x - 1 <= n - y - 1) mn = 1;
		else {
			mn = min(n, 1 + (x - n + y));
		}
		if (x - 1 >= n - y) mx = n;
		else {
			mx = n - (n - y - x + 1);
		}
		printf("%d %d\n", mn, mx);
	}
	return 0;
}