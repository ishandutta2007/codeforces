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
 
const int N = 4e6 + 5;

int n, P, f[N], s[N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}


int main() {
    read(n), read(P);
    f[n] = s[n] = 1;
    for (int i = n - 1; i; i--) {
        f[i] = s[i + 1];
        for (int z = 2; i * z <= n; z++) {
            int t = s[i * z], l = min((i + 1) * z - 1, n);
            t -= s[l + 1];
            if (t < 0) t += P;
            add(f[i], t);
        }
        s[i] = (s[i + 1] + f[i]);
        if (s[i] >= P) s[i] -= P;
    }
    printf("%d\n", f[1]);
    return 0;
}