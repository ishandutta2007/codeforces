#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 2e5 + 5;

int n, l, r, c[N], s[N], ans;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		read(n); read(l); read(r); ans = 0;
		for (int i = 1; i <= n; i++) s[i] = 0;
		for (int i = 1; i <= n; i++) {
			read(c[i]);
			if (i <= l) {
				s[c[i]]++;
			} else {
				s[c[i]]--;
			}
		}
		int ts1 = 0, ts2 = 0;
		int t1 = 0, t2 = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] > 0) {
				t1 += s[i];
				ts1 += s[i] / 2;
			} else {
				t2 += -s[i];
				ts2 += -s[i] / 2;
			}
		}
		int v = min(t1, t2);
		ans += min(t1, t2);
		//cout << ans << endl;
		t1 -= v;
		t2 -= v;
		if (t1) {
			ans += t1 / 2 + max(t1 / 2 - ts1, 0);
		} 
		if (t2) {
			//cout << t2 << " " << ts2 << endl;
			ans += t2 / 2 + max(t2 / 2 - ts2, 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}