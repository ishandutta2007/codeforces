#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second

#define N 300105

int n;
int a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	LL ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		LL sum = a[i] + a[n + 1  - i];
		ans += sum * sum;
	}
	printf("%lld\n", ans);
	return 0;
}