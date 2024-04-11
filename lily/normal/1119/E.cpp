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
int main() {
	read(n);
	LL ans = 0, tmp = 0;
	for (int i = 1; i <= n; i++) {
		int y;
		read(y);
		LL x = y;
		LL g = min(tmp, x / 2ll);
		x -= 2 * g;
		tmp -= g;
		ans += g;
		ans += x / 3;
		tmp += x % 3;
	}
	cout << ans << endl;
	return 0;
}