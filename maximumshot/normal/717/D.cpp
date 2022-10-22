#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) { return (a + b) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }
inline int raz(int a, int b) { return ((a - b) % mod + mod) % mod; }

int binpow(int n, int p) {
    if(p == 0) return 1;
    int q = binpow(n, p / 2);
    q = mul(q, q);
    if(p % 2) q = mul(q, n);
    return q;
}

typedef vec< vec< double > > matrix;

matrix E;

matrix ml(matrix const & a, matrix const & b) {
    int n = (int)a.size();
    int m = (int)a[0].size();
    int k = (int)b[0].size();
    matrix res(n, vec< double >(k));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < k;j++) {
            for(int t = 0;t < m;t++) {
                res[i][j] += a[i][t] * b[t][j];
            }
        }
    }
    return res;
}

matrix bp(matrix n, int p) {
    if(p == 0) return E;
    matrix q = bp(n, p / 2);
    q = ml(q, q);
    if(p % 2) q = ml(q, n);
    return q;
}

int const SZ = 130;

bool solve() {

    E.resize(SZ, vec< double >(SZ));
    for(int i = 0;i < SZ;i++) E[i][i] = 1.0;

    cout.precision(10);
    cout << fixed;

    int n, x;

    cin >> n >> x;

    vec< double > p(SZ);

    for(int i = 0;i <= x;i++) cin >> p[i];

    matrix sq(SZ, vec< double >(SZ));

    for(int now = 0;now < SZ;now++) {
        for(int add = 0;add <= x;add++) {
            if((now ^ add) >= SZ) continue;
            sq[now][now ^ add] = p[add];
        }
    }

    matrix st(SZ, vec< double>(1));

    st[0][0] = 1.0;

    sq = bp(sq, n);
    st = ml(sq, st);

    cout << 1.0 - st[0][0] << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}