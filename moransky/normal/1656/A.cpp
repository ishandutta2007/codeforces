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

const int N = 1e5 + 5;

int main() {
    int T; read(T);
    while (T--) {
        int n; read(n);
        int mx = -2e9, mn = 2e9;
        int p, q;
        for (int i = 1; i <= n; i++) {
            int x; read(x);
            if (chkMax(mx, x)) p = i;
            if (chkMin(mn, x)) q = i;
        }
        printf("%d %d\n", p, q);
    }   
    return 0;
}