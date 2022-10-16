// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n;

char a[N << 1], b[N << 1], c[N << 1];

int inline ask(char *a) {
	int res = 0;
	for (int i = 1; i <= 2 * n; i++) res += (a[i] == '0');
	return res;
}

int main() {
	int T; scanf("%d", &T);
	int o = 0; bool f = 0;
	while (T--) {
		o++;
		scanf("%d%s%s%s", &n, a + 1, b + 1, c + 1);
		int c1 = ask(a), c2 = ask(b), c3 = ask(c);
		int t1 = c1 >= 2 * n - c1, t2 = c2 >= 2 * n - c2, t3 = c3 >= 2 * n - c3;
		if (n == 5 && o == 1) {
			f = 1;
		}

		if (t1 == t3) {
 			for (int i = 1; i <= 2 * n; i++) b[i] = c[i];
 			swap(t2, t3);
		} else if (t2 == t3) {
			for (int i = 1; i <= 2 * n; i++) a[i] = c[i];
			swap(t1, t3);
		}
		bool o = 1;
		// if (f) {
		// 	puts("CAONIMA");
		// 	continue;
		// }

		if (t1 == 1) {
			int i = 1, j = 1;
			while (i <= 2 * n || j <= 2 * n) {
				while (i <= 2 * n && a[i] == '1') {
					putchar(a[i++]);
				}
				while (j <= 2 * n && b[j] == '1') {
					putchar(b[j++]);
				}
				if ((i <= 2 * n && a[i] == '0') || (j <= 2 * n && b[j] == '0')) {
					putchar('0');
					if (i <= 2 * n && a[i] == '0') i++;
					if (j <= 2 * n && b[j] == '0') j++;
				}
				if (i <= 2 * n && a[i] != '1' && a[i] != '0') {
					cout << "FUCKCF";
					return 0;
				}
				if (j <= 2 * n && b[j] != '1' && b[j] != '0') {
					cout << "FUCK";
					return 0;
				}
			}
			puts("");
		} else {
			int i = 1, j = 1;
			while (i <= 2 * n || j <= 2 * n) {
				while (i <= 2 * n && a[i] == '0') {
					putchar(a[i++]);
				}
				while (j <= 2 * n && b[j] == '0') {
					putchar(b[j++]);
				}
				if ((i <= 2 * n && a[i] == '1') || (j <= 2 * n && b[j] == '1')) {
					putchar('1');
					if (i <= 2 * n && a[i] == '1') i++;
					if (j <= 2 * n && b[j] == '1') j++;
				}
				if (i <= 2 * n && a[i] != '1' && a[i] != '0') {
					cout << "FUCK";
					return 0;
				}
				if (j <= 2 * n && b[j] != '1' && b[j] != '0') {
					cout << "FUCK";
					return 0;
				}
			}
			puts("");
		}
	}
	return 0;
}