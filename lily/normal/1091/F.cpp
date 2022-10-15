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
LL a[100005];
char s[100005];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	scanf("%s", s + 1);
	bool water = 0;
	LL tot = 0, wc = 0, gc = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'W') water = 1;
		if (s[i] == 'W') {
			wc += a[i];
			tot += a[i] * 2;
		}
		else if (s[i] == 'G') {
			LL ww = min(wc, a[i]);
			wc -= ww;
			a[i] -= ww;
			tot += ww * 2;
			gc += ww * 2;

			gc += a[i];
			tot += a[i] * 3;
		}
		else {
			tot += a[i];
			LL ww = min(wc, a[i]);
			wc -= ww;
			a[i] -= ww;
			tot += ww;
			LL gg = min(gc, a[i]);
			gc -= gg;
			a[i] -= gg;
			tot += gg * 2;
			if (water) tot += a[i] * 3;
			else tot += a[i] * 5;
		}
		//cerr << tot << endl;
	}
	printf("%lld\n", tot);
	return 0;
}