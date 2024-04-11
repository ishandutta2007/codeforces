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

const int N = 2e5 + 5, B = 500;

vector <pii> qry[N];
vector <int> g[N];
ll ans[N];
int sum[N], val[N];
int n, all;

void add(int x) {
    ++all;
    if (x <= 200000) {
        ++val[x];
        ++sum[(x - 1) / B + 1];
    }
}

int query(int x) {
    int ans = 0;
    while (x % B != 0) ans += val[x], --x;
    while (x) ans += sum[x / B], x -= B;
    return ans;
}

int main() {
    for (int i = 1; i <= 200000; i++) {
        for (int j = i * 2; j <= 200000; j += i) {
            g[j].push_back(i);
        }
    }
    read(n);
    for (int i = 1; i <= n; i++) {
        int l, r;
        read(l); read(r);
        qry[r].emplace_back(l, i);
        ans[i] = 1ll * (r - l + 1) * (r - l) * (r - l - 1) / 6;
    }
    for (int i = 1; i <= 200000; i++) {
        for (auto k : g[i]) for (auto j : g[i]) {
            if (j >= k) break;
            add(j);
            int x = j * 2, y = k * 2;
            if (i % x != 0 && x < i && x + k >= i) add(min(x, k));
            if (i % y != 0 && y < i && j + y >= i) add(j);
            if (i % x != 0 && i % y != 0 && y < i && x + y >= i) add(x);
        }
        for (auto j : qry[i]) {
            ans[j.second] -= (all - query(j.first - 1));
        }
    }
    for (int i = 1; i <= n; i++) print(ans[i], '\n');
    return 0;
}