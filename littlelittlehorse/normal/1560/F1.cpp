#include<bits/stdc++.h>

using namespace std;

int test, n, m, c[11];
int b[11];

int small(int v) {
	int res = 10;
	for (; v; res = min(res, v % 10), v /= 10);
	return res;
}

bool check(int v) {
	bool d[10];
	memset(d, false, sizeof(d));
	for (; v; d[v % 10] = true, v /= 10);
	int cnt = 0;
	for (int i = 0; i < 10; i++)
		if (d[i])
			++cnt;
	return cnt <= m;
}

int main(){
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d%d", &n, &m);
		if (check(n)) {
			printf("%d\n", n);
			continue;
		}
		int cnt = 0;
		for (; n; c[++cnt] = n % 10, n /= 10);
		for (int i = 1, j = cnt; i < j; i++, j--)
			swap(c[i], c[j]);
		for (int i = cnt; i; --i) {
			memset(b, false, sizeof(b));
			int v = 0;
			for (int j = 1; j < i; j++) {
				++b[c[j]];
				v = v * 10 + c[j];
			}
			if (c[i] != 9) {
				int y = v;
				v = v * 10 + c[i] + 1;
				--b[c[i]];
				++b[c[i] + 1];
				v = y;
				v = v * 10 + c[i] + 1;
				for (int j = i + 1; j <= cnt; j++)
					v = v * 10;
				if (check(v)) {
					printf("%d\n", v);
					break;
				}

				v = y;
				v = v * 10 + c[i] + 1;
				int u = small(v);
				for (int j = i + 1; j <= cnt; j++)
					v = v * 10 + u;
				if (check(v)) {
					printf("%d\n", v);
					break;
				}

				--b[c[i] + 1];
				int w = 0;
				for (int j = c[i] + 1; j < 10; j++)
					if (b[j]) {
						w = j;
						break;
					}
				if (w) {
					v = y;
					v = v * 10 + w;
					for (int j = i + 1; j <= cnt; j++)
						v = v * 10;
					if (check(v)) {
						printf("%d\n", v);
						break;
					}
				
					v = y;
					v = v * 10 + w;
					u = small(v);
					for (int j = i + 1; j <= cnt; j++)
						v = v * 10 + u;
					if (check(v)) {
						printf("%d\n", v);
						break;
					}
				}
			}
		}
	}
}