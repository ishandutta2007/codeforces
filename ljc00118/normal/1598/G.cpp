#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 5e5 + 5, M = 3, md[M] = {998244353, 1000000007, 666233};

struct hash_t { int a[M]; };

hash_t operator + (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < M; i++) {
        ans.a[i] = a.a[i] + b.a[i];
        if (ans.a[i] >= md[i]) ans.a[i] -= md[i];
    }
    return ans;
}

hash_t operator - (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < M; i++) {
        ans.a[i] = a.a[i] - b.a[i];
        if (ans.a[i] < 0) ans.a[i] += md[i];
    }
    return ans;
}

hash_t operator * (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < M; i++) ans.a[i] = 1ull * a.a[i] * b.a[i] % md[i];
    return ans;
}

bool operator == (const hash_t a, const hash_t b) {
    for (int i = 0; i < M; i++) if (a.a[i] != b.a[i]) return 0;
    return 1;
}

char s[N], x[N];
hash_t h1[N], h2[N], pw[N];
int n, m;

hash_t ghs1(int l, int r) { return h1[r] - h1[l - 1] * pw[r - l + 1]; }
hash_t ghs2(int l, int r) { return h2[r] - h2[l - 1] * pw[r - l + 1]; }

int main() {
    scanf("%s%s", s + 1, x + 1); n = strlen(s + 1); m = strlen(x + 1);
    pw[0] = (hash_t) {1, 1, 1};
    for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * (hash_t) {10, 10, 10};
    for (int i = 1; i <= n; i++) h1[i] = h1[i - 1] * (hash_t) {10, 10, 10} + (hash_t) {s[i] - '0', s[i] - '0', s[i] - '0'};
    for (int i = 1; i <= m; i++) h2[i] = h2[i - 1] * (hash_t) {10, 10, 10} + (hash_t) {x[i] - '0', x[i] - '0', x[i] - '0'};
    if (m != 1) {
        for (int i = 1; i <= n - m + 2; i++) {
            int l = i, r = i + m - 2;
            if (l > m - 1 && ghs1(l, r) + ghs1(l - m + 1, l - 1) == h2[m]) {
                printf("%d %d\n%d %d\n", l - m + 1, l - 1, l, r);
                return 0;
            }
            if (r < n - m + 2 && ghs1(l, r) + ghs1(r + 1, r + m - 1) == h2[m]) {
                printf("%d %d\n%d %d\n", l, r, r + 1, r + m - 1);
                return 0;
            }
        }
    }
    for (int i = 1; i <= n - m + 1; i++) {
        int l = 1, r = m, match = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ghs1(i, i + mid - 1) == ghs2(1, mid)) match = mid, l = mid + 1;
            else r = mid - 1;
        }
        if (match == m || s[i + match] > x[match + 1]) continue;
        int len = m - match;
        if (i > len && ghs1(i, i + m - 1) + ghs1(i - len, i - 1) == h2[m]) {
            printf("%d %d\n%d %d\n", i - len, i - 1, i, i + m - 1);
            return 0;
        }
        if (i + m + len - 1 <= n && ghs1(i, i + m - 1) + ghs1(i + m, i + m + len - 1) == h2[m]) {
            printf("%d %d\n%d %d\n", i, i + m - 1, i + m, i + m + len - 1);
            return 0;
        }
        if (len == 1) continue;
        --len;
        if (i > len && ghs1(i, i + m - 1) + ghs1(i - len, i - 1) == h2[m]) {
            printf("%d %d\n%d %d\n", i - len, i - 1, i, i + m - 1);
            return 0;
        }
        if (i + m + len - 1 <= n && ghs1(i, i + m - 1) + ghs1(i + m, i + m + len - 1) == h2[m]) {
            printf("%d %d\n%d %d\n", i, i + m - 1, i + m, i + m + len - 1);
            return 0;
        }
    }
    return 0;
}