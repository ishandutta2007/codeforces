#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


const int N = 1e3 + 5;
int n;
int a[N][N];
int f[N * 2];
int getf(int x) {return f[x] == x ? x : (f[x] = getf(f[x]));}
void merge(int x, int y) {
	f[getf(x)] = getf(y);
}

void work() {
	read(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", a[i] + j);
		}
	}
	for (int i = 1; i <= n + n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j][i] != a[i][j]) {
				if (a[j][i] < a[i][j]) {
					if (getf(i) != getf(j) && getf(i + n) != getf(j + n)) {
						merge(i, j + n);
						merge(i + n, j);
					}
				} else {
					if (getf(i) != getf(j + n) && getf(i + n) != getf(j)) {
						merge(i, j);
						merge(i + n, j + n);
					}
				}
			}
		}
	}
	vector <int> ans(n + n + 2);
	for (int i = 1; i <= n; i++) {
		if (!ans[getf(i)] && !ans[getf(i + n)]) {
			ans[getf(i)] = 2; 
			ans[getf(i + n)] = 3;
		}
		else if (ans[getf(i)]) ans[getf(i + n)] = ans[getf(i)] ^ 1;
		else ans[getf(i + n)] = ans[getf(i)] ^ 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d%c", (ans[getf(i)] == 3) ^ (ans[getf(j)] == 3) ? a[j][i] : a[i][j], j == n ? '\n' : ' ');
		}
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();
}