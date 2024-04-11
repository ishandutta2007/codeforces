#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5005, M = 675;

int a[N][M], s[N][M];
int pri[N], cnt[N], height[N];
int n, len, maxn, _cnt; ll ans = 0x7fffffffffffffff;

int lcs(int *a, int *b) {
    int pos = len;
    while (a[pos] == b[pos]) --pos;
    return pos + 1;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        int k; read(k);
        if (k == 0) k = 1;
        if (!cnt[k]) ++_cnt;
        ++cnt[k];
        maxn = max(maxn, k);
    }
    if (_cnt == 1) { print(0, '\n'); return 0; }
    for (int i = 2; i <= maxn; i++) {
        bool ok = 1;
        for (int j = 2; j * j <= i; j++) if (i % j == 0) { ok = 0; break; }
        if (ok) pri[++len] = i;
    }
    for (int i = 1; i <= maxn; i++) {
        memcpy(a[i], a[i - 1], sizeof(a[i]));
        int x = i;
        for (int j = 1; j <= len && pri[j] <= x; j++) while (x % pri[j] == 0) ++a[i][j], x /= pri[j];
        for (int j = len; j >= 1; j--) s[i][j] = s[i][j + 1] + a[i][j];
    }
    for (int i = 1; i < maxn; i++) height[i] = lcs(a[i], a[i + 1]);
    for (int i = 1; i < maxn; i++) {
        ll sum = 0;
        int pos = height[i], minn = min(a[i][pos - 1], a[i + 1][pos - 1]), tmp = s[i][pos] + minn;
        for (int j = i; j >= 1; j--) {
            sum += 1ll * cnt[j] * (tmp + s[j][1] - 2 * (s[j][pos] + minn));
            if (j == 1) break;
            if (height[j - 1] <= pos) minn = min(minn, a[j - 1][pos - 1]);
            else pos = height[j - 1], minn = min(a[j - 1][pos - 1], a[j][pos - 1]);
        }
        pos = height[i], minn = min(a[i][pos - 1], a[i + 1][pos - 1]);
        for (int j = i + 1; j <= maxn; j++) {
            sum += 1ll * cnt[j] * (tmp + s[j][1] - 2 * (s[j][pos] + minn));
            // if (i == 4) fprintf(stderr, "%d : tmp = %d, s[j][1] = %d, dep[lca] = (%d + %d), pos = %d\n", j, tmp, s[j][1], s[j][pos], minn, pos);
            if (j == maxn) break;
            if (height[j] <= pos) minn = min(minn, a[j + 1][pos - 1]);
            else pos = height[j], minn = min(a[j][pos - 1], a[j + 1][pos - 1]);
        }
        // if (sum == 61110) fprintf(stderr, "i = %d, sum = %I64d\n", i, sum);
        ans = min(ans, sum);
    }
    for (int i = 1; i < maxn; i++) {
        ll sum = 0;
        int pos = height[i], minn = min(a[i][pos - 1], a[i + 1][pos - 1]), tmp = s[i + 1][1];
        for (int j = i; j >= 1; j--) {
            sum += 1ll * cnt[j] * (tmp + s[j][1] - 2 * (s[j][pos] + minn));
            if (j == 1) break;
            if (height[j - 1] <= pos) minn = min(minn, a[j - 1][pos - 1]);
            else pos = height[j - 1], minn = min(a[j - 1][pos - 1], a[j][pos - 1]);
        }
        pos = height[i + 1], minn = min(a[i + 1][pos - 1], a[i + 2][pos - 1]);
        for (int j = i + 2; j <= maxn; j++) {
            sum += 1ll * cnt[j] * (tmp + s[j][1] - 2 * (s[j][pos] + minn));
            // if (i == 4) fprintf(stderr, "%d : tmp = %d, s[j][1] = %d, dep[lca] = (%d + %d), pos = %d\n", j, tmp, s[j][1], s[j][pos], minn, pos);
            if (j == maxn) break;
            if (height[j] <= pos) minn = min(minn, a[j + 1][pos - 1]);
            else pos = height[j], minn = min(a[j][pos - 1], a[j + 1][pos - 1]);
        }
        // if (sum == 61110) fprintf(stderr, "i = %d, sum = %I64d\n", i, sum);
        ans = min(ans, sum);
    }
    print(ans, '\n');
    return 0;
}