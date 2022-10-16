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
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

typedef pair<int, int> PII;
 
int L1 = 2e9, L2 = 2e9, R1 = 2e9, R2 = 2e9;

const int N = 2e5 + 5;

int n;

PII L[N], R[N];

bool inline check(int X, int Y) {
    PII x = mp(X, Y);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (x.fi >= L[i].fi && x.fi <= R[i].fi && x.se >= L[i].se && x.se <= R[i].se) c++;
    }  
    return c >= n - 1;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(L[i].fi), read(L[i].se);
        read(R[i].fi), read(R[i].se);
        if (R[i].fi < L1) L2 = L1, L1 = R[i].fi;
        else if (R[i].fi < L2) L2 = R[i].fi;

        if (R[i].se < R1) R2 = R1, R1 = R[i].se;
        else if (R[i].se < R2) R2 = R[i].se;
    }
    if (check(L1, R1)) {
        printf("%d %d\n", L1, R1);
    } else if (check(L2, R1)) {
        printf("%d %d\n", L2, R1);
    } else if (check(L1, R2)) {
        printf("%d %d\n", L1, R2);
    } else if (check(L2, R2)) {
        printf("%d %d\n", L2, R2);
    }
    return 0;
}