// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 105 + 5;

int n, v, c[N];

int main() {
    int T; read(T);
    while (T--) {
        memset(c, 0, sizeof c);
        read(n);
        while (n--) {
            int v; read(v);
            if (v < 0) v *= -1;
            c[v]++;
        }
        int ans = min(c[0], 1);
        for (int i = 1; i <= 100; i++) {
            ans += min(c[i], 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}