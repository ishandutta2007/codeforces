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

const int N = 105;

int f[N][N * N], g[N][N * N], ans[N];
int q, n, k;

int main() {
    f[1][1] = 233;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= 5050; j++) {
            if (!f[i][j]) continue;
            for (int k = 2; k <= 101 - i; k++) {
                if (!f[i + k - 1][j + k * (k + 1) / 2 - 1]) {
                    f[i + k - 1][j + k * (k + 1) / 2 - 1] = k;
                    g[i + k - 1][j + k * (k + 1) / 2 - 1] = 1;
                }
            }
            for (int k = 4; k <= 101 - i; k++) {
                if (!f[i + k - 1][j + k]) {
                    f[i + k - 1][j + k] = k;
                    g[i + k - 1][j + k] = 2;
                }
            }
        }
    }
    read(q);
    while (q--) {
        read(n); read(k); int tmp = n;
        if (n == 1 && k == 1) {
            printf("YES\n1\n");
            continue;
        }
        // printf("! %d %d\n", f[n][k], g[n][k]);
        if (!f[n][k]) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        vector <pii> seq;
        while (n != 1 || k != 1) {
            seq.push_back(make_pair(f[n][k], g[n][k]));
            if (g[n][k] == 1) {
                int tmp = f[n][k];
                k -= (tmp * (tmp + 1) / 2 - 1);
                n -= (tmp - 1);
            } else {
                int tmp = f[n][k];
                k -= tmp;
                n -= (tmp - 1);
            }
        }
        int l = 1, r = tmp, pos = 0, opt = 0;
        for (int i = 0; i < (int)seq.size(); i++) {
            if (seq[i].second == 1) {
                if (opt == 0) {
                    for (int j = 1; j < seq[i].first; j++) ans[++pos] = l + j - 1;
                    l += (seq[i].first - 1); opt ^= 1;
                } else {
                    for (int j = 1; j < seq[i].first; j++) ans[++pos] = r - j + 1;
                    r -= (seq[i].first - 1); opt ^= 1;
                }
            } else {
                if (seq[i].first % 2 == 0) {
                    for (int j = 2; j <= seq[i].first - 2; j += 2) ans[++pos] = l + j - 1;
                    ans[++pos] = r;
                    for (int j = 1; j <= seq[i].first - 3; j += 2) ans[++pos] = l + j - 1;
                    l += (seq[i].first - 2); --r;
                } else {
                    for (int j = 2; j <= seq[i].first - 3; j += 2) ans[++pos] = l + j - 1;
                    ans[++pos] = r - 1;
                    for (int j = 1; j <= seq[i].first - 4; j += 2) ans[++pos] = l + j - 1;
                    ans[++pos] = r;
                    l += (seq[i].first - 3); r -= 2;
                }
            }
        }
        ans[++pos] = l;
        for (int i = 1; i <= tmp; i++) print(ans[i], i == tmp ? '\n' : ' ');
    }
    return 0;
}