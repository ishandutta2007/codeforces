#include <cstdio>
#include <iostream>
using namespace std;
const int N = 200005;
int n, a[N], tot, R1[N], R2[N];
char s[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s + 1); tot = 0;
		for (int i = 1; i <= n; i++) R1[i] = R2[i] = 0;
		for (int i = n - 1; i; i--) {
			if (s[i] == '<') {
				R1[i] = 1;
				if (s[i + 1] == '<') R1[i] += R1[i + 1];
			}
			if (s[i] == '>') {
				R2[i] = 1;
				if (s[i + 1] == '>') R2[i] += R2[i + 1];
			}
		}
		int top = n;
		for (int i = 1; i < n; i++) {
			if (s[i] == '<') {
				int p = top - R1[i];
				for (int j = p; j <= top; j++) a[++tot] = j;
				top = p - 1;
				i = i + R1[i] - 1;
			} else if (s[i] == '>') {
				int p = top - R2[i] + 2;
				if (i == 1) p--;
				if (i + R2[i] - 1 == n - 1) p--;
				for (int j = top; j >= p; j--) a[++tot] = j;
				top = p - 1;
				i = i + R2[i] - 1;
			}
		}
		for (int i = 1; i <= tot; i++) printf("%d ", a[i]);
		puts("");
		top = 1; tot = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '<') {
				int p = top + R1[i] - 2;
				if (i == 1) p++;
				if (i + R1[i] - 1 == n - 1) p++;
				for (int j = top; j <= p; j++) a[++tot] = j;
				top = p + 1;
				i = i + R1[i] - 1;
			} else if (s[i] == '>') {
				int p = top + R2[i];
				for (int j = p; j >= top; j--) a[++tot] = j;
				top = p + 1;
				i = i + R2[i] - 1;
			}
		}
		for (int i = 1; i <= tot; i++) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}