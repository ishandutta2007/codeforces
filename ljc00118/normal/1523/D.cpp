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

const int N = 2e5 + 5;

int a[N][65], val[N];
char c[65];
int ans[65], cnt[1 << 15];
int n, m, p, maxn;

inline int R() { return (rand() << 15) ^ rand(); }

int main() {
    int st = clock();
    srand(time(0));
    read(n); read(m); read(p);
    for (int i = 1; i <= n; i++) {
        scanf("%s", c);
        for (int j = 0; j < m; j++) a[i][j] = c[j] - '0';
    }
    while (clock() - st < CLOCKS_PER_SEC * 2.5) {
        memset(cnt, 0, sizeof(cnt));
        memset(val, 0, sizeof(val));
        int pos = R() % n + 1, now = 0;
        vector <int> b;
        for (int i = 0; i < m; i++) {
            if (a[pos][i]) {
                for (int j = 1; j <= n; j++) {
                    if (a[j][i]) val[j] |= (1 << now);
                }
                ++now;
                b.push_back(i);
            }
        }
        // fprintf(stderr, "pos = %d\n", pos);
        for (int i = 1; i <= n; i++) ++cnt[val[i]];//, fprintf(stderr, "val[%d] = %d\n", i, val[i]);
        for (int mid = 1; mid < (1 << now); mid <<= 1) {
            for (int i = 0; i < (1 << now); i += (mid << 1)) {
                for (int j = 0; j < mid; j++) {
                    cnt[i + j] += cnt[i + j + mid];
                }
            }
        }
        for (int i = 0; i < (1 << now); i++) {
            // fprintf(stderr, "cnt[%d] = %d\n", i, cnt[i]);
            if (cnt[i] >= (n + 1) / 2 && __builtin_popcount(i) > maxn) {
                memset(ans, 0, sizeof(ans));
                maxn = __builtin_popcount(i);
                for (int j = 0; j < now; j++) {
                    if ((i >> j) & 1) {
                        ans[b[j]] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) putchar(ans[i] + '0');
    putchar('\n');
    return 0;
}