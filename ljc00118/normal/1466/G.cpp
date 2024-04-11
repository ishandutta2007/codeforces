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

const int N = 1e5 + 5, md = 1e9 + 7, inv2 = (md + 1) / 2;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int mod[2] = {998244353, 1000000007};

struct hash_t { int h[2]; };

const hash_t base = (hash_t) {666233, 19260817};

hash_t operator + (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < 2; i++) {
        ans.h[i] = (a.h[i] + b.h[i]) % mod[i];
    }
    return ans;
}

hash_t operator - (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < 2; i++) {
        ans.h[i] = (a.h[i] - b.h[i] + mod[i]) % mod[i];
    }
    return ans;
}

hash_t operator * (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < 2; i++) {
        ans.h[i] = 1ll * a.h[i] * b.h[i] % mod[i];
    }
    return ans;
}

bool operator < (const hash_t a, const hash_t b) {
    for (int i = 0; i < 2; i++) {
        if (a.h[i] != b.h[i]) return a.h[i] < b.h[i];
    }
    return 0;
}

bool operator != (const hash_t a, const hash_t b) {
    for (int i = 0; i < 2; i++) {
        if (a.h[i] != b.h[i]) return 1;
    }
    return 0;
}

map <hash_t, int> hh;
hash_t hpw[N], hs[105], hc[N * 10];
char s0[105], t[N], c[N * 10];
int ipw[N], s[N][26];
int n, k, q, slen, len;

hash_t gethash(hash_t *h, int l, int r) {
    return h[r] - h[l - 1] * hpw[r - l + 1];
}

int solve(int now, vector <char> str) {
    if (now > k) return 0;
    if ((int)str.size() == 1) return sub(s[k][str[0] - 'a'], s[now - 1][str[0] - 'a']);
    int cando[2] = {1, 1};
    vector <char> ntr[2];
    for (int i = 0; i < (int)str.size(); i += 2) {
        ntr[0].push_back(str[i]);
        if (str[i] != t[now]) cando[0] = 0;
    }
    for (int i = 1; i < (int)str.size(); i += 2) {
        ntr[1].push_back(str[i]);
        if (str[i] != t[now]) cando[1] = 0;
    }
    int ans = 0;
    if (cando[0]) ans = add(ans, solve(now + 1, ntr[1]));
    if (cando[1]) ans = add(ans, solve(now + 1, ntr[0]));
    return ans;
}

int check(char *s, char *t, int len) {
    for (int i = 0; i < len; i++) {
        if (s[i] != t[i]) return 0;
    }
    return 1;
}

int main() {
    read(n); read(q);
    scanf("%s%s", s0 + 1, t + 1); slen = strlen(s0 + 1);
    hpw[0] = (hash_t) {1, 1};
    for (int i = 1; i <= 100000; i++) hpw[i] = hpw[i - 1] * base;
    for (int i = 1; i <= slen; i++) hs[i] = hs[i - 1] * base + (hash_t) {s0[i], s0[i]};
    for (int i = 1; i <= slen; i++) {
        for (int j = i; j <= slen; j++) ++hh[gethash(hs, i, j)];
    }
    ipw[0] = 1;
    for (int i = 1; i <= n; i++) {
        ipw[i] = mul(ipw[i - 1], inv2);
        memcpy(s[i], s[i - 1], sizeof(s[i]));
        s[i][t[i] - 'a'] = add(s[i][t[i] - 'a'], ipw[i]);
    }
    while (q--) {
        read(k); scanf("%s", c + 1); len = strlen(c + 1);
        for (int i = 1; i <= len; i++) hc[i] = hc[i - 1] * base + (hash_t) {c[i], c[i]};
        int ans = 0;
        for (int i = 1; i <= min(slen + 1, len); i++) {
            if (i > 1 && gethash(hs, slen - i + 2, slen) != gethash(hc, 1, i - 1)) continue;
            int cando = 1;
            vector <char> str;
            for (int j = i; j <= len; j += slen + 1) {
                int plen = min(len - j, slen);
                if (plen && gethash(hs, 1, plen) != gethash(hc, j + 1, j + plen)) {
                    cando = 0;
                    break;
                }
                str.push_back(c[j]);
            }
            if (!cando) continue;
            ans = add(ans, mul(fpow(2, k), solve(1, str)));
        }
        if (len <= slen && hh.count(hc[len])) ans = add(ans, mul(hh[hc[len]], fpow(2, k)));
        print(ans, '\n');
    }
    return 0;
}