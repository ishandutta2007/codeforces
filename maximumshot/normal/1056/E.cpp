#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

const int P1 = 37;
const int P2 = 43;
const int mod1 = inf + 7;
const int mod2 = inf + 21;
const pii pp = {P1, P2};
const pii zz = {0, 0};
const pii ee = {1, 1};

inline pii _sum(pii p1, pii p2) {
    return make_pair(
        p1.first  + p2.first  < mod1 ? p1.first  + p2.first  : p1.first  + p2.first  - mod1,
        p1.second + p2.second < mod2 ? p1.second + p2.second : p1.second + p2.second - mod2
    );
}

inline pii _sub(pii p1, pii p2) {
    return make_pair(
        p1.first  >= p2.first  ? p1.first  - p2.first  : p1.first  - p2.first  + mod1,
        p1.second >= p2.second ? p1.second - p2.second : p1.second - p2.second + mod2
    );
}

inline pii _mul(pii p1, pii p2) {
    return make_pair(
        (1ll * p1.first  * p2.first)  % mod1,
        (1ll * p1.second * p2.second) % mod2
    );
}

inline pii _code(char c) {
    return make_pair(
        c - 'a' + 1,
        c - 'a' + 1
    );
}

const int N = 1e6 + 5;

char s[N];
char t[N];
pii pw[N];
int n, m;
pii ht[N];

inline pii get_hash(int l, int r) {
    return _sub(ht[r], _mul(l ? ht[l - 1] : zz, pw[r - l + 1]));
}

int main() {

    pw[0] = ee;
    for(int i = 1;i < N;i++) {
        pw[i] = _mul(pw[i - 1], pp);
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%s %s", s, t);

    n = strlen(s);
    m = strlen(t);

    if(s[0] == '1') {
        for(int i = 0;i < n;i++) {
            s[i] = s[i] == '0' ? '1' : '0';
        }
    }

    for(int i = 0;i < m;i++) {
        if(i) ht[i] = ht[i - 1];
        ht[i] = _sum(_mul(ht[i], pp), _code(t[i]));
    }

    int c0 = 0;
    int c1 = 0;

    for(int i = 0;i < n;i++) {
        if(s[i] == '0') {
            c0++;
        }else {
            c1++;
        }
    }

    int pref = 0;
    while(s[pref] == '0') pref++;

    vec< pii > s0(m + 1), s1(m + 1);
    vec< int > pos[2];

    for(int i = 0;i < n;i++) {
        pos[ s[i] - '0' ].push_back(i);
    }

    vec< pii > dp(n + 1);

    for(int i = n - 1;i >= 0;i--) {
        dp[i] = dp[i + 1];
        if(i + 1 < n) {
            if(s[i + 1] == '0') {
                dp[i].first++;
            }else {
                dp[i].second++;
            }
        }
    }

    for(int l0 = 1;l0 * c0 < m;l0++) {
        int l1 = (m - c0 * l0);
        if(l1 % c1) continue;
        l1 /= c1;

        for(int p0 : pos[0]) {
            s0[l0] = _sum(s0[l0], pw[ dp[p0].first * l0 + dp[p0].second * l1 ]);
        }
    }

    for(int l1 = 1;l1 * c1 < m;l1++) {
        int l0 = m - c1 * l1;
        if(l0 % c0) continue;
        l0 /= c0;

        for(int p1 : pos[1]) {
            s1[l0] = _sum(s1[l0], pw[ dp[p1].first * l0 + dp[p1].second * l1 ]);
        }
    }

    int res = 0;

//    cout << "c0 = " << c0 << " c1 = " << c1 << "\n";

    for(int l0 = 1;l0 < m;l0++) {
        if(c0 * l0 > m) break;
        int l1 = (m - c0 * l0);
        if(l1 % c1) continue;
        l1 /= c1;

//        cout << l0 << ", " << l1 << " = ("  << s0[l0].first << ", " << s1[l0].first << ")\n";

        pii h0 = get_hash(0, l0 - 1);
        pii h1 = get_hash(pref * l0, pref * l0 + l1 - 1);

        pii H0 = _mul(h0, s0[l0]);
        pii H1 = _mul(h1, s1[l0]);
        pii tot = _sum(H0, H1);

        if(tot == get_hash(0, m - 1) && h0 != h1) {
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}