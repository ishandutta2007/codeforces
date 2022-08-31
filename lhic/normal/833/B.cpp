#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 1e5;
const int INF = 1e7;

int lst[MAXN];
int pr[MAXN];
int a[MAXN];
int dp[MAXN];
int dp2[MAXN];
int rmq[MAXN * 4];
int dd[MAXN * 4];

void build(int v, int tl, int tr) {
    dd[v] = 0;
    if (tl + 1 == tr) {
        rmq[v] = dp[tl];
        return;
    }
    int m = (tl + tr) >> 1;
    build(v * 2 + 1, tl, m);
    build(v * 2 + 2, m, tr);
    rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void add(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        ++rmq[v], ++dd[v];
        return;
    }
    int m = (tl + tr) >> 1;
    add(v * 2 + 1, tl, m, l, r);
    add(v * 2 + 2, m, tr, l, r);
    rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

int get(int v, int tl, int tr, int l, int r) {
    if (r <= tl || r <= tl)
        return -INF;
    if (l <= tl && tr <= r)
        return rmq[v];
    int m = (tl + tr) >> 1;
    return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) + dd[v];
}

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i), --a[i];
    for (int i = 0; i < n; ++i)
        lst[i] = -1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        pr[i] = lst[a[i]];
        lst[a[i]] = i;
        if (pr[i] == -1) {
            ++cur;
        }
        dp[i] = cur;
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j < i - 1; ++j)
            dp2[j] = -INF;
        build(0, 0, n);
        for (int j = i - 1; j < n; ++j) {
            add(0, 0, n, max(0, pr[j]), j);
            dp2[j] = get(0, 0, n, 0, j);
        }
        for (int j = 0; j < n; ++j)
            dp[j] = dp2[j];
    }
    cout << dp[n - 1] << "\n";
    return 0;
}