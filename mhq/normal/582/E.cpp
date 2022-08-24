#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
int msk[16];
int val[16];
int n;
const int AND = 0;
const int OR = 1;
const int ANY = -1;
const int maxN = 505;
const int LG = 16;
const int PW = (1 << LG);
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
void and_fft(vector < int >& a, bool invert) {
    assert(a.size() == PW);
    for (int bit = 0; bit < LG; bit++) {
        for (int mask = 0; mask < PW; mask++) {
            if (mask & (1 << bit)) {
                int u = a[mask];
                int v = a[mask ^ (1 << bit)];
                if (!invert) {
                    a[mask ^ (1 << bit)] = sum(v, u);
                    a[mask] = u;
                }
                else {
                    a[mask ^ (1 << bit)] = sub(v, u);
                    a[mask] = u;
                }
            }
        }
    }
}
void or_fft(vector < int >& a, bool invert) {
    assert(a.size() == PW);
    for (int bit = 0; bit < LG; bit++) {
        for (int mask = 0; mask < PW; mask++) {
            if (mask & (1 << bit)) {
                int u = a[mask];
                int v = a[mask ^ (1 << bit)];
                if (!invert) {
                    a[mask ^ (1 << bit)] = v;
                    a[mask] = sum(u, v);
                }
                else {
                    a[mask ^ (1 << bit)] = v;
                    a[mask] = sub(u, v);
                }
            }
        }
    }
}
int le[maxN], ri[maxN];
int op[maxN];
int tp[maxN];
int sz;
int solve(int l, int r) {
    if (l == r) {
        sz++;
        if (s[l] >= 'A' && s[l] <= 'D') {
            tp[sz] = 4 + (s[l] - 'A');
        }
        else if (s[l] >= 'a' && s[l] <= 'd') {
            tp[sz] = s[l] - 'a';
        }
        else {
            assert(s[l] == '?');
            tp[sz] = -1;
        }
        le[sz] = ri[sz] = -1;
        op[sz] = -1;
        return sz;
    }
    assert(s[l] == '(');
    int bal = 0;
    int where = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') bal++;
        else if (s[i] == ')') bal--;
        if (bal == 0) {
            where = i;
            break;
        }
    }
    assert(where != -1);
    int c1 = solve(l + 1, where - 1);
    assert(s[where + 1] == '?' || s[where + 1] == '|' || s[where + 1] == '&');
    int c2 = solve(where + 3, r - 1);
    sz++;
    le[sz] = c1; ri[sz] = c2;
    if (s[where + 1] == '?') op[sz] = ANY;
    else if (s[where + 1] == '&') op[sz] = AND;
    else op[sz] = OR;
    return sz;
}
vector < int > dfs(int root) {
    if (le[root] == -1) {
        vector < int > f(PW);
        if (tp[root] == -1) {
            for (int i = 0; i < 8; i++) {
                int res_mask = 0;
                int d = i - 4;
                if (d < 0) d += 4;
                for (int mask = 0; mask < 16; mask++) {
                    int need_bit = (mask >> d) & 1;
                    if (!need_bit ^ (i >= 4)) res_mask |= (1 << mask);
                }
                f[res_mask] = sum(f[res_mask], 1);
            }
        }
        else {
            for (int i = tp[root]; i < tp[root] + 1; i++) {
                int res_mask = 0;
                int d = i - 4;
                if (d < 0) d += 4;
                for (int mask = 0; mask < 16; mask++) {
                    int need_bit = (mask >> d) & 1;
                    if (!need_bit ^ (i >= 4)) res_mask |= (1 << mask);
                }
                f[res_mask] = sum(f[res_mask], 1);
            }
        }
        return f;
    }
    auto c1 = dfs(le[root]);
    auto c2 = dfs(ri[root]);
    vector < int > cp1 = c1;
    vector < int > cp2 = c2;
    vector < int > got(PW);
    if (op[root] == ANY || op[root] == OR) {
        or_fft(c1, false);
        or_fft(c2, false);
        for (int msk = 0; msk < PW; msk++) {
            c1[msk] = mult(c1[msk], c2[msk]);
        }
        or_fft(c1, true);
        for (int msk = 0; msk < (1 << 16); msk++) {
            got[msk] = sum(got[msk], c1[msk]);
        }
        c1 = cp1;
        c2 = cp2;
    }
    if (op[root] == ANY || op[root] == AND) {
        and_fft(c1, false);
        and_fft(c2, false);
        for (int msk = 0; msk < PW; msk++) {
            c1[msk] = mult(c1[msk], c2[msk]);
        }
        and_fft(c1, true);
        for (int msk = 0; msk < (1 << 16); msk++) {
            got[msk] = sum(got[msk], c1[msk]);
        }
        c1 = cp1;
        c2 = cp2;
    }
    return got;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    memset(msk, -1, sizeof msk);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cin >> msk[i];
        val[i] = a + 2 * b + 4 * c + 8 * d;
    }
    int root = solve(0, s.size() - 1);
    auto got = dfs(root);
    int tot = 0;
    for (int i = 0; i < PW; i++) {
        bool good = true;
        for (int j = 0; j < n; j++) {
            if (((i >> val[j]) & 1) != msk[j]) {
                good = false;
                break;
            }
        }
        if (good) {
            tot = sum(tot, got[i]);
        }
    }
    cout << tot;
    return 0;
}