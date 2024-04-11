#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void plusle(int &a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
}
void minun(int &a, int b) {
    a -= b;
    while (a < 0) a += MOD;
}
int add(int a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    return a;
}
int sub(int a, int b) {
    a -= b;
    while (a < 0) a += MOD;
    return a;
}
int mul(int a, int b) {
    return int64_t(a) * b % MOD;
}
int power(int a, int64_t b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}
const int nax = 4e5 + 10;
int n;
map <int, int> com;
int x[nax];
int y[nax];
int sz[nax];
bool not_tree[nax];
int par[nax];
int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) {
        not_tree[x] = true;
        return;
    }
    sz[x] += sz[y];
    par[y] = x;
    not_tree[x] = not_tree[x] | not_tree[y];
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0 ; i < nax ; ++ i) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i] >> y[i];
        if (!com.count(x[i])) {
            int sz = com.size();
            com[x[i]] = sz;
        }
        if (!com.count(y[i])) {
            int sz = com.size();
            com[y[i]] = sz;
        }
        unite(com[x[i]], 200000 + com[y[i]]);
    }
    int ans = 1;

    for (int i = 0 ; i < nax ; ++ i) {
        if (i == find(i) && sz[i] > 1) {
            if (not_tree[i])
                ans = mul(ans, power(2, sz[i]));
            else
                ans = mul(ans, sub(power(2, sz[i]), 1));
        }
    }
    cout << ans << '\n';
}