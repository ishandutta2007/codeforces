#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int mod = inf + 7;
const int N = 1e6 + 5;

inline int mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

int binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = mul(res, tmp);
        }
        pw >>= 1;
        tmp = mul(tmp, tmp);
    }
    return res;
}

int fact[N];
int rfact[N];
int pw_m[N];
int pw_n[N];

int CNK(int n, int k) {
    if(n < k) return 0;
    int res = mul(rfact[k], rfact[n - k]);
    return mul(res, fact[n]);
}

int up_fact(int from, int cnt) {
    if(cnt <= 0) return 1;
    return mul(fact[from + cnt - 1], from ? rfact[from - 1] : 1);
}

int down_fact(int from, int cnt) {
    if(cnt <= 0) return 1;
    return mul(fact[from], from >= cnt ? rfact[from - cnt] : 1);
}

int n, m, aaa, bbb;

void build() {
    fact[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    rfact[N - 1] = binpow(fact[N - 1], mod - 2);
    for(int i = N - 2;i >= 0;i--) {
        rfact[i] = mul(rfact[i + 1], i + 1);
    }
    pw_m[0] = pw_n[0] = 1;
    for(int i = 1;i < N;i++) {
        pw_m[i] = mul(pw_m[i - 1], m);
        pw_n[i] = mul(pw_n[i - 1], n);
    }
}

int cnt_tree(int cnt_vertex) {
    if(cnt_vertex <= 1) return 1;
    return binpow(cnt_vertex, cnt_vertex - 2);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m >> aaa >> bbb;

    build();

    int res = 0;

    for(int i = 1;i < n && i <= m;i++) {
        int fi = CNK(m - 1, m - i);
        int k1 = down_fact(n - 2, i - 1);
        int k2 = 1;
        int k3 = i + 1 < n ? mul(i + 1, pw_n[n, n - i - 2]) : 1;
        int k4 = pw_m[n - 1 - i];
        int tmp = mul(fi, k1);
        tmp = mul(tmp, k2);
        tmp = mul(tmp, k3);
        tmp = mul(tmp, k4);
        res = sum(res, tmp);
    }

    cout << res << "\n";

    return 0;
}