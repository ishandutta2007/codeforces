#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005, P = 998244353;

typedef long long LL;

typedef pair<int, int> PII;

int n, K, a[N], tot;

LL ans = 0;

int cnt = 1;

PII e[N];

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) scanf("%d", &e[i].first), e[i].second = i;
	sort(e + 1, e + 1 + n, greater<PII>() );
	for (int i = 1; i <= K; i++) a[++tot] = e[i].second, ans += e[i].first;
	sort(a + 1, a + 1 + tot);
	for (int i = 1; i < K; i++) {
		cnt = (LL) cnt * (a[i + 1] - a[i]) % P;
	}
	printf("%lld %d\n", ans, cnt);
	return 0;
}