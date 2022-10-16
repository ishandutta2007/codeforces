#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

int n;

int inline ask(int i) {
	printf("? %d\n", i);
	fflush(stdout);
	int x; read(x);
	return x;
}

void inline out(int i) {
	printf("! %d\n", i);
	fflush(stdout);
	exit(0);
}

int oppo(int x) {
	if (x <= n / 2) return x + n / 2;
	return x - n / 2; 
}

int main() {
	read(n);
	int A = ask(1), B = ask(oppo(1));
	if (A == B) out(1);
	else {
		if ((n / 2) & 1) {
			out(-1);
		}
		int a = 1, b = 1 + n / 2;
		if (B < A) a += n, swap(a, b);
		int l = a + 1, r = b - 1;
		if (l > r) {
			out(-1);
		}
		while (l <= r) {
			int mid = (l + r) >> 1;
			int p = ask(mid), q = ask(oppo(mid));
			if (p == q) {
				out(mid);
			}
			if (p < q) l = mid + 1;
			else r = mid - 1;
		}
	}
}