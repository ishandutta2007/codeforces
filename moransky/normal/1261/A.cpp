#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 2005;

int n, k, L[N], R[N], m;

char s[N], g[N];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &n, &k, s + 1);
        --k;
        for (int i = 1; i <= k; i++) {
            g[i * 2 - 1] = '(';
            g[i * 2] = ')';
        }
        int l = k * 2 + 1, r = n;
        while (l < r) {
            g[l++] = '(';
            g[r--] = ')';
        }
        m = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] != g[i]) {
                for (int j = i + 1; j <= n; j++) {
                    if (s[j] == g[i]) {
                        ++m;
                        L[m] = i, R[m] = j;
                        reverse(s + L[m], s + 1 + R[m]);
                        break;
                    }
                }
            }
        }
        printf("%d\n", m);
        for (int i = 1; i <= m; i++) printf("%d %d\n", L[i], R[i]);
    }
    return 0;
}