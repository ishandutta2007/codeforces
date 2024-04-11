#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 2e5 + 10;
int n, c[maxn], d[maxn];
char a[maxn], b[maxn];
void work() {
	scanf("%d%s%s", &n, a + 1, b + 1);
	vector <pii> vec;
	a[0] = b[0] = '0';
	for (int i = 1; i <= n; ++i) c[i] = a[i] ^ a[i - 1], d[i] = b[i] ^ b[i - 1] ^ c[i];
	vi pos;
	for (int i = 1; i <= n; ++i) if (c[i]) pos.push_back(i);
	for (int i = 2; i <= n; ++i) if (d[i]) return printf("NO\n"), void();
	if ((d[1] & 1) != (pos.size() & 1)) {
		if (n == 1) return printf("NO\n"), void();
		vec.push_back({1, n - 1}), vec.push_back({n, n}), vec.push_back({1, n});
	}
	for (int i : pos) vec.push_back({i, n});
	printf("YES\n%d\n", (int) vec.size());
	for (pii p : vec) printf("%d %d\n", p.fir, p.sec);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}