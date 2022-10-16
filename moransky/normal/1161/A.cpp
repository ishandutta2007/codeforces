// Skyqwq
#include <iostream>
#include <cstdio>

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

const int N = 1e5 + 5;

int n, k, x[N], R[N], L[N], ans;

void inline work(int a, int b) {
	if (a == b) {
		if (!R[a]) ans++;
	} else {
		if (!R[a] || !R[b]) ans++;
		else {
			if (R[a] < L[b]) ans++;
		}
	}
}
 
int main() {
	read(n), read(k);
	for (int i = 1; i <= k; i++) {
		read(x[i]), R[x[i]] = i;
		if (!L[x[i]]) L[x[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		work(i, i);
		if (i > 1) work(i, i - 1);
		if (i < n) work(i, i + 1);
	}
	print(ans);
	return 0;
}