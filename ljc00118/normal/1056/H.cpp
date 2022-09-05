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

const int N = 3e5 + 5, B = 90;

unordered_map <int, ull> ha[N];
vector <int> a[N];
int id[N];
ull ha1[N], ha2[N];
int T, n, m;

ull seed = 416;
inline ull R() {
    seed ^= seed << 17;
    seed ^= seed >> 13;
    seed ^= seed << 5;
    return seed;
}

int main() {
    for (int i = 1; i <= 300000; i++) {
        ha1[i] = R();
        ha2[i] = R();
    }
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= m; i++) {
            int k; read(k);
            a[i].resize(k);
            for (int j = 0; j < k; j++) read(a[i][j]);
        }
        for (int i = 1; i <= n; i++) ha[i].clear();
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int k = (int)a[i].size();
            if (k > B) continue;
            for (int j = 0; j < k; j++) {
                ull now = 0;
                for (int t = j; t < k; t++) {
                    now += (ha1[a[i][t]] * ha2[t - j + 1]);
                    if (ha[a[i][j]].count(a[i][t])) {
                        if (ha[a[i][j]][a[i][t]] != now) {
                            ans = 1;
                            break;
                        }
                    } else ha[a[i][j]][a[i][t]] = now;
                }
                if (ans) break;
            }
            if (ans) break;
        }
        if (ans) {
            printf("Human\n");
            continue;
        }
        for (int i = 1; i <= m; i++) {
            int k = (int)a[i].size();
            if (k <= B) continue;
            for (int j = 0; j < k; j++) id[a[i][j]] = j + 1;
            for (int j = 1; j <= m; j++) {
                if (i == j || a[j].size() > a[i].size()) continue;
                int minn = n + 1, las = n + 1;
                for (int t = 0; t < (int)a[j].size(); t++) {
                    if (id[a[j][t]]) {
                        if (id[a[j][t]] != las + 1 && id[a[j][t]] > minn) {
                            ans = 1;
                            break;
                        }
                        las = id[a[j][t]]; minn = min(minn, id[a[j][t]]);
                    } else {
                        las = n + 1;
                    }
                }
                if (ans) break;
            }
            for (int j = 0; j < k; j++) id[a[i][j]] = 0;
            if (ans) break;
        }
        if (ans) printf("Human\n");
        else printf("Robot\n");
    }
    return 0;
}