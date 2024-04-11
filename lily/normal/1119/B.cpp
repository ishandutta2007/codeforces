#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define N 1234567
int n;

LL h;
LL a[N], b[N];

bool ok(int x) {
	for (int i = 1; i <= x; i++) b[i] = a[i];
	sort(b + 1, b + x + 1);
	LL tot = 0;
	for (int i = x; i > 0; ) {
		tot += b[i];
		i -= 2;
	}
	return tot <= h;
}

int main() {
	read(n); cin >> h;
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (ok(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;


	return 0;
}