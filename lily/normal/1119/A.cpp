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
int a[1231234];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	int ans = 0, x = 1, y = 2;
	for (int i = 2; i <= n; i++) if (a[i] != a[1]) {y = i; break;}
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[1]) ans = max(ans, i - 1);
		if (a[i] != a[y]) ans = max(ans, i - y);
	}
	cout << ans << endl;
	return 0;
}