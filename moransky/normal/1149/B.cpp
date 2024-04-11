// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 255, S = 1e5 + 5, M = 1e3 + 5, INF = 0x3f3f3f3f;

int n, q, f[N][N][N], R[S][26];

char s[S], op[4];

char A[M], B[M], C[M];

int t1, t2, t3;

int main() {
	read(n), read(q);
	scanf("%s", s + 1);
	for (int i = n; i; i--) {
		for (int j = 0; j < 26; j++)
			R[i][j] = R[i + 1][j];
		R[i][s[i] - 'a'] = i;
	}
	memset(f, 0x3f, sizeof f);
	f[0][0][0] = 0;
	while (q--) {
		scanf("%s", op); int w; read(w);
		if (*op == '+') {
			scanf("%s", op);
			char c = *op;
			if (w == 1) {
				A[++t1] = c;
				
				for (int j = 0; j <= t2; j++) {
					for (int k = 0; k <= t3; k++) {
						int v = f[t1 - 1][j][k];
						if (v == INF) continue;
						if (R[v + 1][A[t1] - 'a']) {
							chkMin(f[t1][j][k], R[v + 1][A[t1] - 'a']);
						}
					}
				}
				for (int j = 0; j <= t2; j++) {
					for (int k = 0; k <= t3; k++) {
						int v = f[t1][j][k];
						if (v == INF) continue;
						if (j < t2 && R[v + 1][B[j + 1] - 'a']) {
							chkMin(f[t1][j + 1][k], R[v + 1][B[j + 1] - 'a']);
						}
						if (k < t3 && R[v + 1][C[k + 1] - 'a']) {
							chkMin(f[t1][j][k + 1], R[v + 1][C[k + 1] - 'a']);
						}
					}
				}
			} else if (w == 2) {
				B[++t2] = c;
				for (int j = 0; j <= t1; j++) {
					for (int k = 0; k <= t3; k++) {
						int v = f[j][t2 - 1][k];
						if (v == INF) continue;
						if (R[v + 1][B[t2] - 'a']) {
							chkMin(f[j][t2][k], R[v + 1][B[t2] - 'a']);
						}
					}
				}
				for (int j = 0; j <= t1; j++) {
					for (int k = 0; k <= t3; k++) {
						int v = f[j][t2][k];
						if (v == INF) continue;
						if (j < t1 && R[v + 1][A[j + 1] - 'a']) {
							chkMin(f[j + 1][t2][k], R[v + 1][A[j + 1] - 'a']);
						}
						if (k < t3 && R[v + 1][C[k + 1] - 'a']) {
							chkMin(f[j][t2][k + 1], R[v + 1][C[k + 1] - 'a']);
						}
					}
				}
			} else {
				C[++t3] = c;
				for (int j = 0; j <= t1; j++) {
					for (int k = 0; k <= t2; k++) {
						int v = f[j][k][t3 - 1];
						if (v == INF) continue;
						if (R[v + 1][C[t3] - 'a']) {
							chkMin(f[j][k][t3], R[v + 1][C[t3] - 'a']);
						}
					}
				}
				for (int j = 0; j <= t1; j++) {
					for (int k = 0; k <= t2; k++) {
						int v = f[j][k][t3];
						if (v == INF) continue;
						if (j < t1 && R[v + 1][A[j + 1] - 'a']) {
							chkMin(f[j + 1][k][t3], R[v + 1][A[j + 1] - 'a']);
						}
						if (k < t2 && R[v + 1][B[k + 1] - 'a']) {
							chkMin(f[j][k + 1][t3], R[v + 1][B[k + 1] - 'a']);
						}
					}
				}
			}
		} else {
			if (w == 1) {
				for (int j = 0; j <= t2; j++) {
					for (int k = 0; k <= t3; k++) {
						f[t1][j][k] = INF;
					}
				}
				--t1;
			} else if (w == 2) {
				for (int j = 0; j <= t1; j++) {
					for (int k = 0; k <= t3; k++) {
						f[j][t2][k] = INF;
					}
				}
				--t2;
			} else {
				for (int j = 0; j <= t1; j++) {
					for (int k = 0; k <= t2; k++) {
						f[j][k][t3] = INF;
					}
				}
				--t3;
			}
		}
		puts(f[t1][t2][t3] != INF ? "Yes" : "No");
	}
	return 0;
}