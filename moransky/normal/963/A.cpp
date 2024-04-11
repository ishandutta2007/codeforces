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

const int P = 1e9 + 9;

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

int inline get(int q, int n) {
    if ((q - 1) % P == 0) return n;
    return (LL)(power(q, n) + P - 1ll) * power(q - 1, P - 2) % P;
}

const int N = 1e5 + 5;

int n, a, b, k;

char s[N];
 
int main() {
    read(n), read(a), read(b), read(k);
    scanf("%s", s);
    int ans = 0;
    int inv = (LL)b * power(a, P - 2) % P;
    inv = power(inv, k);
    for (int i = 0; i < k; i++) {
        int t = (n - i) / k;
        int v = (LL)power(a, n - i) * power(b, i) % P;
        int w = get(inv, t + 1);
        v = 1ll * v * w % P;
        if (s[i] == '-') ans = (ans - v + P) % P;
        else (ans += v) %= P;
    }
    printf("%d\n", ans);
    return 0;
}