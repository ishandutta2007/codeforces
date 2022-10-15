#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

const int maxn = 30005;
const int mov = 320;

int f[maxn][650], bucket[maxn];

inline int sort3(int a, int b, int c) { return a > b ? (a > c ? a : c) : (b > c ? b : c); }

signed main() {
    int n = read<int>(), m = read<int>();
    int p;
    for (int i = 1; i <= n; i++) bucket[p = read<int>()]++;
    memset(f, -0x3f, sizeof(f));
    int ans = f[m][mov] = bucket[0] + bucket[m];
    for (int i = m + 1; i <= p; i++)
        for (int o = -mov; o <= mov; o++) {
            if (m + o > 0 && m + o <= i)
                f[i][mov + o] = max(f[i][mov + o], sort3(f[i - (m + o)][mov + o], f[i - (m + o)][mov + o - 1], f[i - (m + o)][mov + o + 1]) + bucket[i]);
            ans = max(ans, f[i][mov + o]);
        }
    printf("%d\n", ans);
    return 0;
}