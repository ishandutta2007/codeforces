#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef tuple <int, int, int, int> pII;
#define fir first
#define sec second

int ask(int i, int j, int k) {
	printf("? %d %d %d\n", i, j, k);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	if (x == -1) exit(0);
	return x;
}

pii calc(pII in) {
	pii a[4];
	tie(a[0].sec, a[1].sec, a[2].sec, a[3].sec) = in;
	a[0].fir = ask(a[1].sec, a[2].sec, a[3].sec);
	a[1].fir = ask(a[2].sec, a[3].sec, a[0].sec);
	a[2].fir = ask(a[3].sec, a[0].sec, a[1].sec);
	a[3].fir = ask(a[0].sec, a[1].sec, a[2].sec);
	sort(a, a + 4);
	return make_pair(a[0].sec, a[1].sec);
}

int n;
void work() {
	scanf("%d", &n);
	pii ans = {1, 2};
	for (int i = 3, j = 4; j <= n; i += 2, j += 2)
		ans = calc(make_tuple(ans.fir, ans.sec, i, j));

	if (n & 1) {
		for (int i = 1; i < n; ++i)
			if (ans.fir != i && ans.sec != i) {
				ans = calc(make_tuple(ans.fir, ans.sec, i, n));
				break;
			}
	}
	printf("! %d %d\n", ans.fir, ans.sec);
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}