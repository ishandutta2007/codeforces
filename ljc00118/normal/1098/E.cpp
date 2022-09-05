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

struct atom {
    ll cntA, cntB, sum;
    atom (ll k1 = 0, ll k2 = 0, ll k3 = 0) : cntA(k1), cntB(k2), sum(k3) {}
};

atom operator + (const atom a, const atom b) {
    return atom(a.cntA + b.cntA, a.cntB + b.cntB, a.sum + b.sum + a.cntB * b.cntA);
}

atom fpow(atom x, ll y) {
    atom ans = atom(0, 0, 0);
    while (y) {
        if (y & 1) ans = ans + x;
        y >>= 1; x = x + x;
    }
    return ans;
}

ll floordiv(ll a, ll x, ll b, ll c) {
    return (ll)(((long double)a * x + b) / c);
}

atom solve(ll a, ll b, ll c, ll n, atom A, atom B) {
    if (a >= c) return solve(a % c, b, c, n, fpow(B, a / c) + A, B);
    if (b >= c) return fpow(B, b / c) + solve(a, b % c, c, n, A, B);
    ll m = floordiv(a, n, b, c);
    if (m == 0) return fpow(A, n);
    ll cnt = n - floordiv(m - 1, c, c - b - 1, a);
    return fpow(A, (c - b - 1) / a) + B + solve(c, (c - b - 1) % a, a, m - 1, B, A) + fpow(A, cnt);
}

ll getf(ll a, ll b, ll c, ll n) {
    // fprintf(stderr, "a = %lld, b = %lld, c = %lld, n = %lld\n", a, b, c, n);
    return solve(a, b, c, n, atom(1, 0, 0), atom(0, 1, 0)).sum;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

const int N = 50005;

struct seg {
    int x, len;
    seg (int k1 = 0, int k2 = 0) : x(k1), len(k2) {}
    bool operator < (const seg A) const { return x < A.x; }
} t[N * 20];

int st[N][16], a[N], lg[N];
int n, len;

int qgcd(int l, int r) {
    int k = lg[r - l + 1];
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

ll s[N * 20], sc[N * 20], all;
ll calc(ll mid) {
    if (s[len] <= mid) return all;
    // fprintf(stderr, "mid = %lld\n", mid);
    ll ans = 0;
    for (int i = 1, j = 1; i <= len; i++) {
        if (t[i].x > mid) break;
        int l = j;
        while (l < len && s[l] + t[l + 1].x - s[i - 1] <= mid) ++l;
        int r = j;
        while (r < len && s[r] + t[r + 1].x - s[i] + t[i].x <= mid) ++r;
        // fprintf(stderr, "i = %d, l = %d, r = %d\n", i, l, r);
        for (int k = l; k <= r; k++) {
            if (i == k) {
                int lim = min((ll)t[i].len, mid / t[i].x), oth = (i == len ? 0 : max(0ll, (mid - t[i + 1].x) / t[i].x));
                ans += (1ll * t[i].len * (t[i].len + 1) / 2 - 1ll * (t[i].len - lim) * (t[i].len - lim + 1) / 2);
                if (oth <= lim) ans -= 1ll * oth * (oth + 1) / 2;
                else ans -= 1ll * lim * (lim + 1) / 2, ans -= 1ll * (oth - lim) * lim;
                // fprintf(stderr, "lim = %d\n", lim);
                // if (i == len || 1ll * t[i].x * t[i].len + t[i + 1].x > mid) ans += lim * (t[i].len - lim + 1);
            } else {
                int L = min((ll)t[i].len, (mid - t[k].x - (s[k - 1] - s[i])) / t[i].x);
                int R = max(1ll, k == len ? 1ll : ((mid - t[k + 1].x - (s[k] - s[i])) / t[i].x + 1));
                {
                    ll LL = sc[k - 1] - sc[i] + R, RR = sc[k - 1] - sc[i] + L;
                    // fprintf(stderr, "LL = %lld, RR = %lld\n", LL, RR);
                    ans += 1ll * RR * (RR + 1) / 2;
                    ans -= 1ll * (LL - 1) * LL / 2;
                }
                int lim = (mid - (s[k] - s[i])) / t[i].x, cando = 1;
                // fprintf(stderr, "i = %d, k = %d, L = %d, R = %d, lim = %d\n", i, k, L, R, lim);
                if (lim >= L) {
                    cando = 0;
                    ans += 1ll * (L - R + 1) * t[k].len;
                } else if (lim >= R) {
                    ans += 1ll * (lim - R + 1) * t[k].len;
                    R = lim + 1;
                }
                if (cando) ans += getf(t[i].x, mid - (s[k - 1] - s[i]) - 1ll * (L + 1) * t[i].x, t[k].x, L - R + 1);
            }
        }
        j = r;
        // fprintf(stderr, "i = %d, ans = %lld\n", i, ans);
    }
    return ans;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), st[i][0] = a[i];
    for (int j = 1; j <= 15; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[0] = -1;
    for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i++) {
        int nowl = i, nowd = a[i];
        while (nowl <= n) {
            int l = nowl, r = n, res = n + 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (qgcd(i, mid) != nowd) {
                    res = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            // fprintf(stderr, "i = %d, nowl = %d, nowd = %d, res = %d\n", i, nowl, nowd, res);
            t[++len] = seg(nowd, res - nowl);
            nowd = qgcd(i, res);
            nowl = res;
        }
    }
    sort(t + 1, t + len + 1);
    // for (int i = 1; i <= len; i++) {
    //     fprintf(stderr, "{%d, %d}\n", t[i].x, t[i].len);
    // }
    for (int i = 1; i <= len; i++) {
        s[i] = s[i - 1] + 1ll * t[i].x * t[i].len;
        sc[i] = sc[i - 1] + t[i].len;
    }
    all = sc[len] * (sc[len] + 1) / 2;
    // fprintf(stderr, "all = %lld, calc(5) = %lld\n", all, calc(5));
    ll l = 1, r = s[len], ans = r;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (calc(mid) >= (all + 1) / 2) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    print(ans, '\n');
    return 0;
}