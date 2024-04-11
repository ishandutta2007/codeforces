#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table; // the usage is the same as the unordered_map

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 22;
const int K = 2005;
const int mod = inf + 7;
const int N = 2e5 + 5;

inline void sub(int &x, int y) {
    if((x -= y) < 0) x += mod;
}

inline void _add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

int binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = (1ll * res * tmp) % mod;
        }
        tmp = (1ll * tmp * tmp) % mod;
        pw >>= 1;
    }
    return res;
}

int fc[N];
int rfc[N];

void precalc() {
    fc[0] = 1;
    for(int i = 1;i < N;i++) {
        fc[i] = (1ll * fc[i - 1] * i) % mod;
    }
    rfc[N - 1] = binpow(fc[N - 1], mod - 2);
    for(int i = N - 2;i >= 0;i--) {
        rfc[i] = (1ll * rfc[i + 1] * (i + 1)) % mod;
    }
}

inline int CNK(int n, int k) {
    if(n < k) return 0;
    int x = (1ll * rfc[k] * rfc[n - k]) % mod;
    return (1ll * x * fc[n]) % mod;
}

inline int C(int nn, int mm) {
    return CNK(nn + mm - 2, nn - 1);
}

struct Cell {
    int i, j, x;
    bool operator == (const Cell &c) const {
        return i == c.i && j == c.j && x == c.x;
    }
    bool operator < (const Cell &c) const {
        return i < c.i || i == c.i && j < c.j;
    }
    int get_dist(const Cell &o) const {
        if(i > o.i || j > o.j) return 0;
        return C(o.i - i + 1, o.j - j + 1);
    }
};

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    precalc();

    int n, m, k, s;

    scanf("%d %d %d %d", &n, &m, &k, &s);

    vector< Cell > a(k);

    for(Cell &c : a) {
        scanf("%d %d", &c.i, &c.j);
        c.x = 1;
    }

    if(find(a.begin(), a.end(), Cell{1, 1, 1}) == a.end()) {
        a.push_back({1, 1, 0});
        k++;
    }

    sort(a.rbegin(), a.rend());

//    for(Cell c : a) {
//        cout << c.i << " " << c.j << "  !\n";
//    }

    vector< vector< int > > dp(k, vector< int >(LOG));

    for(int j = 0;j < LOG;j++) {
        for(int i = 0;i < k;i++) {
            dp[i][j] = a[i].get_dist({n, m, 0});
            for(int j2 = 0;j2 < j;j2++) {
                sub(dp[i][j], dp[i][j2]);
            }
            for(int i2 = 0;i2 < i;i2++) {
                int tmp = (1ll * a[i].get_dist(a[i2]) * dp[i2][j]) % mod;
                sub(dp[i][j], tmp);
            }
        }
    }

    int denum = Cell({1, 1, 0}).get_dist({n, m, 0});
    int num = 0;
    int cnt = denum;

//    cout << "denum = " << denum << "\n";

    Cell st = a[k - 1];

//    for(int i = 0;i < k;i++) {
//        for(int j = 0;j <= 5;j++) {
//            cout << "(" << i << ", " << j << ") = " << dp[i][j] << " ?? \n";
//        }
//    }

    for(int curs = s, j = 0;j < LOG;j++, curs = (curs + 1) >> 1) {
        if(j < st.x) continue;
        _add(num, (1ll * dp[k - 1][j - st.x] * curs) % mod);
//        cout << "j = " << j << ", cnt = " << dp[k - 1][j - st.x] << " ?\n";
        sub(cnt, dp[k - 1][j - st.x]);
    }

//    cout << "ost = " << cnt << "\n";

    _add(num, cnt);

    int result = (1ll * num * binpow(denum, mod - 2)) % mod;

    printf("%d\n", result);

    return 0;
}