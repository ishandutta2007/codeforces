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

vector <int> vec[N];
vector <pii> vec2[N];
int x[N], v[N], b[N], ans[N];
ll s[N];
int T, n, m, len;

int main() {
    read(T);
    while (T--) {
        len = 0;
        read(n); read(m);
        for (int i = 1; i <= n; i++) {
            read(x[i]); read(v[i]);
            b[++len] = x[i]; ans[i] = 1;
        }
        sort(b + 1, b + len + 1); len = unique(b + 1, b + len + 1) - b - 1;
        for (int i = 1; i <= len; i++) vec[i].clear(), vec2[i].clear(), s[i] = 0;
        for (int i = 1; i <= n; i++) {
            x[i] = lower_bound(b + 1, b + len + 1, x[i]) - b;
            vec[x[i]].push_back(i);
            int l = lower_bound(b + 1, b + len + 1, b[x[i]] - v[i]) - b;
            int r = upper_bound(b + 1, b + len + 1, b[x[i]] + v[i]) - b;
            vec2[l].emplace_back(v[i] - b[x[i]], 1);
            vec2[x[i]].emplace_back(-(v[i] - b[x[i]]), -1);
            vec2[x[i]].emplace_back(v[i] + b[x[i]], -1);
            vec2[r].emplace_back(-(v[i] + b[x[i]]), 1);
        }
        ll s1 = 0, s2 = 0;
        for (int i = 1; i <= len; i++) {
            for (auto j : vec2[i]) {
                s1 += j.first;
                s2 += j.second;
            }
            s[i] = s1 + s2 * b[i];
        }
        ll maxn = -1e18;
        for (int i = 1; i <= len; i++) {
            if (s[i] > m) {
                maxn = max(maxn, s[i] - m - b[i]);
            }
            for (auto j : vec[i]) {
                if (v[j] - b[i] < maxn) {
                    ans[j] = 0;
                }
            }
        }
        maxn = -1e18;
        for (int i = len; i >= 1; i--) {
            if (s[i] > m) {
                maxn = max(maxn, s[i] - m + b[i]);
            }
            for (auto j : vec[i]) {
                if (v[j] + b[i] < maxn) {
                    ans[j] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) putchar(ans[i] + '0');
        putchar('\n');
    }
    return 0;
}