#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
 mt19937 rnd(std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count());
const int mods[3] = {998244353, (int)1e9 + 7, (int)1e9 + 9};
int pt[3];
const int maxN = 2 * (int)1e5 + 10;
int n, q;
char c[maxN];
int sum(int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b, int mod) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int binpw(int a, int b, int mod) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, binpw(a, b - 1, mod), mod);
    int res = binpw(a, b / 2, mod);
    return mult(res, res, mod);
}


int pw[3][maxN];
int inv[3][maxN];
struct hsh{
    int f[2][3];
    int cnt;
    int zero;
    hsh(int x) {
        cnt = 1;
        zero = (x == 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                f[j][i] = 0;
            }
        }
        if (x == 0) {
            for (int i = 0; i < 3; i++) {
                f[0][i] = 1;
            }
        }
    }
    hsh() {
        cnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                f[j][i] = 0;
            }
        }
    }

};
hsh merge(const hsh& a, const hsh& b) {
    hsh c;
    c.cnt = a.cnt + b.cnt;
    c.zero = a.zero + b.zero;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c.f[i][j] = sum(a.f[i][j], mult(b.f[i ^ (a.cnt % 2)][j], pw[j][a.zero], mods[j]), mods[j]);
        }
    }
    return c;
}

hsh t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = hsh(c[tl] - '0');
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm +1 ,tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
hsh get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
    else return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 3; i++) {
        pt[i] = rnd() % mods[i];
        if (pt[i] < 0) pt[i] += mods[i];
    }
    for (int i = 0; i < 3; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < maxN; j++) {
            pw[i][j] = mult(pw[i][j - 1], pt[i], mods[i]);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        auto h1 = get(1, 1, n, l1, l1 + len - 1);
        auto h2 = get(1, 1, n, l2, l2 + len - 1);
        bool ok = true;
        if (h1.cnt != h2.cnt) ok = false;
        if (h1.zero != h2.zero) ok = false;
        for (int p = 0; p < 3; p++) {
            for (int j = 0; j < 2; j++) {
                if (h1.f[j][p] != h2.f[j][p]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}