#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second

int n;
int a[300005];

map <int, int> g[2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	g[0][0] = 1;
	long long ans = 0;
	int su = 0;
	for (int i = 1; i <= n; i++) su ^= a[i], ans += g[i & 1][su], g[i & 1][su]++;
	printf("%lld\n", ans);



	return 0;
}