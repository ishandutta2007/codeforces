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

const int N = 1e5 + 5, B = 130, LEN = 2, md[LEN] = {998244353, 1000000007};

struct hash_t { int a[LEN]; } ha[2][N], pw[N];

const hash_t base = (hash_t) {101, 103};

hash_t operator + (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < LEN; i++) {
        ans.a[i] = (a.a[i] + b.a[i]) % md[i];
    }
    return ans;
}

hash_t operator - (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < LEN; i++) {
        ans.a[i] = (a.a[i] - b.a[i] + md[i]) % md[i];
    }
    return ans;
}

hash_t operator * (const hash_t a, const hash_t b) {
    hash_t ans;
    for (int i = 0; i < LEN; i++) {
        ans.a[i] = 1ll * a.a[i] * b.a[i] % md[i];
    }
    return ans;
}

bool operator == (const hash_t a, const hash_t b) {
    for (int i = 0; i < LEN; i++) {
        if (a.a[i] != b.a[i]) return 0;
    }
    return 1;
}

vector <int> qry[N], st2[B + 5][17];
char s[N], t[N];
int sa[N], rk[N], st[N][18], lg[N], l[N], r[N], k[N], x[N], y[N], ans[N];
int n, m, q;

inline hash_t gethash(int id, int l, int r) {
    return ha[id][r] - ha[id][l - 1] * pw[r - l + 1];
}

int dcmp(int id1, int id2, int s1, int s2, int len) {
    int l = 1, r = len, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (gethash(id1, s1, s1 + mid - 1) == gethash(id2, s2, s2 + mid - 1)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (ans == len) return -1;
    char c1 = (id1 == 0 ? s[s1 + ans] : t[s1 + ans]);
    char c2 = (id2 == 0 ? s[s2 + ans] : t[s2 + ans]);
    return c1 < c2;
}

struct seg { int id, l, r; } a[3], b[3];

bool cmp(int x, int y) {
    if (x == y) return 0;
    int rev = 0;
    if (x > y) swap(x, y), rev = 1;
    a[0] = (seg) {0, 1, x}; a[1] = (seg) {1, 1, m}; a[2] = (seg) {0, x + 1, n};
    b[0] = (seg) {0, 1, y}; b[1] = (seg) {1, 1, m}; b[2] = (seg) {0, y + 1, n};
    int p1 = 1, p2 = 0, l1 = 0, l2 = x;
    while (p1 <= 2) {
        int len1 = (a[p1].r - a[p1].l + 1) - l1;
        int len2 = (b[p2].r - b[p2].l + 1) - l2;
        int res = dcmp(a[p1].id, b[p2].id, a[p1].l + l1, b[p2].l + l2, min(len1, len2));
        // fprintf(stderr, "p1 = %d, l1 = %d, p2 = %d, l2 = %d, res = %d\n", p1, l1, p2, l2, res);
        if (res != -1) return res ^ rev;
        l1 += min(len1, len2); l2 += min(len1, len2);
        while (p1 <= 2 && l1 >= a[p1].r - a[p1].l + 1) {
            l1 -= (a[p1].r - a[p1].l + 1);
            ++p1;
        }
        while (p2 <= 2 && l2 >= b[p2].r - b[p2].l + 1) {
            l2 -= (b[p2].r - b[p2].l + 1);
            ++p2;
        }
    }
    return rev ^ 1;
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int query(int id, int l, int r) {
    int k = lg[r - l + 1];
    return min(st2[id][k][l], st2[id][k][r - (1 << k) + 1]);
}

int main() {
    scanf("%s%s", s + 1, t + 1); n = strlen(s + 1); m = strlen(t + 1); read(q);
    pw[0] = {1, 1};
    for (int i = 1; i <= 100000; i++) pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= n; i++) ha[0][i] = ha[0][i - 1] * base + (hash_t) {s[i] - 'a' + 1, s[i] - 'a' + 1};
    for (int i = 1; i <= m; i++) ha[1][i] = ha[1][i - 1] * base + (hash_t) {t[i] - 'a' + 1, t[i] - 'a' + 1};
    // cout << cmp(3, 6) << endl;
    // return 0;
    for (int i = 0; i <= n; i++) sa[i] = i;
    sort(sa, sa + n + 1, cmp);
    vector <int> vis(n + 1, 0);
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         fprintf(stderr, "cmp(%d, %d) = %d\n", i, j, cmp(i, j));
    //     }
    // }
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    for (int i = 0; i <= n; i++) st[i][0] = rk[i];
    // for (int i = 0; i <= n; i++) fprintf(stderr, "rk[%d] = %d\n", i, rk[i]);
    lg[0] = -1;
    for (int i = 1; i <= n + 1; i++) lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= 16; j++) {
        for (int i = 0; i <= n - (1 << j) + 1; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= q; i++) {
        read(l[i]); read(r[i]); read(k[i]); read(x[i]); read(y[i]);
        // if (i == 33) {
            // cout << cmp(55411, 54568) << " " << (rk[55411] < rk[54568]) << endl;
            // return 0;
        // }
        if (k[i] <= B) qry[k[i]].push_back(i);
        else qry[0].push_back(i);
    }
    for (int _ = 0; _ < (int)qry[0].size(); _++) {
        int i = qry[0][_], L = x[i], R = y[i], res = n + 1;
        while (L <= n) {
            int _l = max(l[i], L), _r = min(r[i], R);
            if (_l <= _r) res = min(res, query(_l, _r));
            L += k[i]; R += k[i];
        }
        ans[i] = res;
    }
    for (int k = 1; k <= B; k++) {
        for (int i = 0; i < k; i++) {
            st2[i][0].clear();
            for (int j = i; j <= n; j += k) st2[i][0].push_back(rk[j]);
            int len = (int)st2[i][0].size() - 1;
            if (len < 0) continue;
            for (int j = 1; j <= 16; j++) {
                st2[i][j].resize(len);
                for (int t = 0; t <= len - (1 << j) + 1; t++) {
                    // fprintf(stderr, "k = %d, i = %d, j = %d, t = %d\n", k, i, j, t);
                    st2[i][j][t] = min(st2[i][j - 1][t], st2[i][j - 1][t + (1 << (j - 1))]);
                }
            }
        }
        for (int _ = 0; _ < (int)qry[k].size(); _++) {
            int i = qry[k][_], res = n + 1;
            for (int j = x[i]; j <= y[i]; j++) {
                if (r[i] < j) break;
                int L = (l[i] - j + k - 1) / k, R = (r[i] - j) / k;
                if (L <= R) res = min(res, query(j, L, R)); 
            }
            ans[i] = res;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i] == n + 1) ans[i] = -1;
        else ans[i] = sa[ans[i]];
        print(ans[i], i == q ? '\n' : ' ');
    }
    return 0;
}