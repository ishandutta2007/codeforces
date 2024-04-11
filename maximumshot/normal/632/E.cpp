#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int mod = 998244353;
const int LOG = 23;
const int ROOT = 31;

int REV(int x, int pw = mod - 2) {
    int res = 1;
    int tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = (1ll * res * tmp) % mod;
        }
        pw >>= 1;
        tmp = (1ll * tmp * tmp) % mod;
    }
    return res;
}

vec< int > rev[LOG + 1];
vec< int > pw[LOG + 1];

void precalc() {
    for(int start = ROOT, lvl = LOG;lvl >= 0;lvl--, start = (1ll * start * start) % mod) {
        int sz = 1 << lvl;
        rev[lvl].resize(sz);
        pw [lvl].resize(sz);

        for(int x = 1;x < sz;x++) {
            rev[lvl][x] = (rev[lvl][x >> 1] >> 1) | ( (x&1) << (lvl - 1) );
        }

        pw[lvl][0] = 1;
        for(int x = 1;x < sz;x++) {
            pw[lvl][x] = (1ll * pw[lvl][x - 1] * start) % mod;
        }
    }
}

void fft(vec< int > &a, int lg, bool invert = 0) {
    assert(lg <= LOG);
    int sz = 1 << lg;
    for(int j, i = 0;i < sz;i++) if((j = rev[lg][i]) > i) swap(a[i], a[j]);
    for(int lvl = 0;lvl < lg;lvl++) {
        int len = 1 << lvl;
        for(int i = 0;i < sz;i += (len << 1)) {
            for(int j = 0;j < len;j++) {
                int f1 = a[i + j];
                int f2 = (1ll * a[i + j + len] * pw[lvl + 1][j]) % mod;
                a[i + j] = f1 + f2 < mod ? f1 + f2 : f1 + f2 - mod;
                a[i + j + len] = f1 >= f2 ? f1 - f2 : f1 - f2 + mod;
            }
        }
    }
    if(invert) {
        int rn = REV(sz);
        reverse(a.begin() + 1, a.end());
        for(int &x : a) x = (1ll * x * rn) % mod;
    }
}

vec< int > multiply(vec< int > a, vec< int > b) {
    int lg;
    {
        int sz = max(a.size(), b.size());
        lg = 0;
        while((1 << lg) <= sz) lg++;
        lg++;
    }
    int sz = 1 << lg;
    a.resize(sz);
    b.resize(sz);
    fft(a, lg);
    fft(b, lg);
    for(int i = 0;i < sz;i++) {
        a[i] = (1ll * a[i] * b[i]) % mod;
    }
    fft(a, lg, 1);
    while(!a.empty() && !a.back()) a.pop_back();
    for(int &x : a) x = !!x;
    return a;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    precalc();

    int n, k;

    scanf("%d %d", &n, &k);

    vec< int > a(1024);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        a[x] = 1;
    }

    vec< int > res = {1}, tmp = a;

    while(k > 0) {
        if(k & 1) {
            res = multiply(res, tmp);
        }
        tmp = multiply(tmp, tmp);
        k >>= 1;
    }

    for(int i = 0;i < (int)res.size();i++) {
        if(res[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}