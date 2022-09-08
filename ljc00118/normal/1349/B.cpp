#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

int a[N];
int T, n, k, ok1, ok2;

int main() {
	read(T);
	while (T--) {
		read(n); read(k); ok1 = ok2 = 0;
		for (int i = 1; i <= n; i++) read(a[i]), ok1 |= (a[i] == k);
		if (n == 1) {
			if (ok1) printf("yes\n");
			else printf("no\n");
			continue;
		}
		for (int i = 1; i < n; i++) {
			ok2 |= (a[i] >= k && a[i + 1] >= k);
			if (i != n - 1) ok2 |= (a[i] >= k && a[i + 2] >= k);
		}
		if (ok1 && ok2) printf("yes\n");
		else printf("no\n");
	}
    return 0;
}