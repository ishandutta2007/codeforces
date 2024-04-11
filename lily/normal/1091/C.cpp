#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


int n;

set <LL> s;

void test(int i) {
	LL y = n / i;
	LL ans = (1 + (y - 1) * i + 1) * y / 2;
	s.insert(ans);
}

int main() {
	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			test(i);
			test(n / i);
		}
	}
	s.insert(n * LL(n + 1) / 2);
	for (auto v : s) {
		printf("%lld ", v);
	}
	return 0;
}