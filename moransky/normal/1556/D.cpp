// Skyqwq
#include <bits/stdc++.h>

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

int inline OR(int i, int j) {
    printf("or %d %d\n", i, j);
    fflush(stdout);
    int x; read(x);
    return x;
}

int inline AND(int i, int j) {
    printf("and %d %d\n", i, j);
    fflush(stdout);
    int x; read(x);
    return x;
}

int inline sum(int i, int j) {
    int c1 = OR(i, j);
    int c2 = AND(i, j);
    return c1 + c2;
}

const int N = 10005;

int n, k, a[N];
 
int main() {
    read(n); read(k);
    LL s12 = sum(1, 2), s13 = sum(1, 3), s23 = sum(2, 3);
    LL s = (s12 + s13 + s23) / 2;
    a[1] = s - s23;
    a[2] = s - s13;
    a[3] = s - s12;
    for (int i = 4; i <= n; i++) {
        LL t = sum(1, i);
        a[i] = t - a[1];
    }
    sort(a + 1, a + 1 + n);
    printf("finish %d\n", a[k]);
    fflush(stdout);
    return 0;
}