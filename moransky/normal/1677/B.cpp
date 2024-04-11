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

const int N = 1e6 + 5;

int n, m, w[N], c[N], d[N], s[N], t[N];

char a[N];

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        scanf("%s", a + 1);
        for (int i = 1; i <= m; i++) {
            int p = -1;
            for (int j = i; j <= n * m; j += m) {
                if (a[j] == '1') {
                    p = j;
                    break;
                }
            }
            if (p != -1) c[p]++;
        }
        for (int i = 1; i <= n * m; i++) {
            s[i] = s[i - 1] + (a[i] == '1' ? 1 : 0);
        }
        for (int i = m; i <= n * m; i++) {
            if ((s[i] - s[i - m]) > 0) {
                d[i]++;
            }
        }
        int pr = 0;
        for (int i = 1; i < m; i++) {
            if (a[i] == '1') {
                pr++;
            }
            if (pr) {
                d[i]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n * m; i++) {
            ans += c[i];
            printf("%d ", ans + t[i % m] + d[i]);
            t[i % m] += d[i];
            
        }
        for (int i = 0; i <= n * m; i++) {
            c[i] = d[i] = t[i] = 0;
        }
        puts("");
    }
    return 0;
}