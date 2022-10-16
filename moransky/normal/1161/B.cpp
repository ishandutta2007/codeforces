// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
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

typedef pair<int, int> PII;

const int N = 2e5 + 5;

int n, m, a[N], b[N];
 
PII A[N], B[N];

int inline work(int k) {
    if (k == n) return 0;
    for (int i = 1; i <= m; i++) {
        A[i] = mp(a[i], b[i]), B[i] = mp((a[i] + k - 1) % n + 1, (b[i] + k - 1) % n + 1);
        if (A[i].fi > A[i].se) swap(A[i].fi, A[i].se);
        if (B[i].fi > B[i].se) swap(B[i].fi, B[i].se);
    }
    sort(A + 1, A + 1 + m);
    sort(B + 1, B + 1 + m);
    for (int i = 1; i <= m; i++)
        if (A[i].fi != B[i].fi || A[i].se != B[i].se) return 0;
    return 1;
}

bool inline check() {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (work(i)) {
                return 1;
            }
            if (work(n / i)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
	read(n), read(m);
    for (int i = 1; i <= m; i++) read(a[i]), read(b[i]);
    puts(check() ? "Yes" : "No");
	return 0;
}