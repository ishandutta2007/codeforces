
#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef long long LL;

int n, a[2123123];

void work() {
	scanf("%d", &n);
	LL xsum = 0;
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		xsum ^= a[i];
		sum += a[i];
	}
	vector <LL> app;
	LL xx = (1ll << 50) ^ (xsum & 1);
	sum += xx;
	xsum ^= xx;
	app.push_back(xx);
	if (xsum * 2 > sum) {
		LL dif = xsum * 2 - sum;
		app.push_back(dif / 2);
		app.push_back(dif / 2);
		sum += dif / 2 * 2;
	}
	printf("%d\n", int(app.size()));
	for (auto v : app) {
		printf("%lld ", v);
	}
	printf("\n");
}

int main() {
	int T;
	cin >> T;
	while (T--) work();


}