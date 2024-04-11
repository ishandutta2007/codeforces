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

const int N = 1e6 + 5;

char s[25], t[25];
int mx[1 << 20], mn[1 << 20];
int a[N], b[N], A[N], B[N], p[N];
int n, m, k, ansl, ansr, ans = -1;

int main() {
    memset(mx, -0x3f, sizeof(mx));
    memset(mn, 0x3f, sizeof(mn));
    read(n); read(m); read(k);
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
    for (int i = 1; i <= k; i++) p[i] = i;
    for (int i = n + 1; i >= 1; i--) {
        if (i != n + 1) {
            int posa = 0, posb = 0;
            for (int j = 1; j <= k; j++) {
                if (p[j] == a[i]) posa = j;
                if (p[j] == b[i]) posb = j; 
            }
            swap(p[posa], p[posb]);
        }
        for (int j = 1; j <= k; j++) {
            if (s[p[j]] == '1') A[i] |= (1 << (j - 1));
            if (t[p[j]] == '1') B[i] |= (1 << (j - 1));
        }
        mn[A[i]] = min(mn[A[i]], i);
        mx[B[i]] = max(mx[B[i]], i);
    }
    for (int i = (1 << k) - 1; i >= 0; i--) {
        if (mx[i] - mn[i] >= m && __builtin_popcount(i) > ans) {
            ans = __builtin_popcount(i);
            ansl = mn[i]; ansr = mx[i] - 1;
        }
        for (int j = 0; j < k; j++) {
            if ((i >> j) & 1) {
                mx[i ^ (1 << j)] = max(mx[i ^ (1 << j)], mx[i]);
                mn[i ^ (1 << j)] = min(mn[i ^ (1 << j)], mn[i]);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        cnt += s[i] - '0';
        cnt += t[i] - '0';
    }
    print(ans + (k - ans - (cnt - ans * 2)), '\n');
    print(ansl, ' '); print(ansr, '\n');
    return 0;
}