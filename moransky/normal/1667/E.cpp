// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

typedef vector<int> Poly;

#define pb push_back

const int N = 8e5 + 5, P = 998244353, G = 3;

int A[N], rev[N], mod, inv[N], fact[N], infact[N];
int lim = 1, len = 0, W[20][N];

int inline power(int a, int b, int Mod = P) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % Mod;
        a = (LL)a * a % Mod;
        b >>= 1;
    }
    return res;
}
int Gi = power(G, P - 2, P), inv2 = power(2, P - 2, P);

void inline NTT(int c[], int lim, int o) {
    for (int i = 0; i < lim; i++)
        if (i < rev[i]) swap(c[i], c[rev[i]]);
    for (int k = 1, t = 0; k < lim; k <<= 1, t++) {
        for (int i = 0; i < lim; i += (k << 1)) {
            for (int j = 0; j < k; j++) {
                int u = c[i + j], v = (LL)c[i + k + j] * W[t][j] % P;
                c[i + j] = u + v >= P ? u + v - P : u + v;
                c[i + j + k] = u - v < 0 ? u - v + P : u - v; 
            }
        }
    }
    if (o == -1) {
        reverse(c + 1, c + lim);
        int inv = power(lim, P - 2, P);
        for (int i = 0; i < lim; i++)
            c[i] = (LL)c[i] * inv % P;
    }
}

void inline setN(int n) {
    lim = 1, len = 0;
    while (lim < n) lim <<= 1, len++;
    for (int i = 0; i < lim; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
}
Poly inline NTT(Poly a, int o) {
    int n = a.size();
    for (int i = 0; i < n; i++) A[i] = a[i];
    NTT(A, lim, o);
    a.clear();
    for (int i = 0; i < lim; i++) a.push_back(A[i]), A[i] = 0;
    return a;
}

Poly inline mul (Poly a, Poly b, int newn = -1) {
    if (newn == -1) newn = a.size() + b.size() - 1;
    setN(a.size() + b.size() - 1);
    Poly c = NTT(a, 1), d = NTT(b, 1);
    for (int i = 0; i < lim; i++) c[i] = (LL)c[i] * d[i] % P;
    d = NTT(c, -1); d.resize(newn);
    return d;
}

//  n
void inline init(int n) {
    setN(2 * n);
    for (int k = 1, t = 0; k < lim; k <<= 1, t++) {
        int wn = power(G, (P - 1) / (k << 1));
        W[t][0] = 1;
        for (int j = 1; j < k; j++) W[t][j] = (LL)W[t][j - 1] * wn % P;
    }
}



void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}


void inline factPrework(int n) {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    infact[n] = power(fact[n], P - 2);
    for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}

int inline C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}


int n, t;

void inline del(int &x, int y) {
    x -= y;
    if (x < 0) x += P;
}

int main() {
    read(n); factPrework(n); init(n);
    t = (n - 1) / 2 + 1;
    Poly a(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i <= n; i++) b[i] = infact[i];
    for (int i = t; i < n; i++) a[i] = 1ll * infact[i] * fact[i - 1] % P * fact[n - i - 1] % P;
    a = mul(a, b);
    Poly c(n + 1, 0), d(n + 1, 0);
    for (int i = 0; i + 1 < t; i++) c[i] = 1ll * fact[n - i - 1 - 1];
    for (int i = 0; i <= n; i++) d[i] = infact[i];
    c = mul(c, d);
    for (int p = 1; p <= n; p++) {
        int w = fact[n - 1];
        del(w, 1ll * a[n - p] * fact[n - p] % P);
        del(w, 1ll * c[n - p] * fact[n - p] % P * (p - 1) % P);
        // for (int i = t; i < n; i++)
        //     del(w, 1ll * C(n - p, i) * fact[i - 1] % P * fact[n - i - 1] % P);
         // for (int i = 0; i + 1 < t; i++)
         //     del(w, 1ll * C(n - p, i) * fact[i] % P * fact[n - i - 1 - 1] % P * (p - 1) % P);
         printf("%d ", w);
    }
    return 0;
}