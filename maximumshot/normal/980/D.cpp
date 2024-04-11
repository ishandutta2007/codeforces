#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int P = 5;
const int mod1 = inf + 7;
const int mod2 = inf + 9;
const pii pp = make_pair(P, P);
const pii zz = make_pair(0, 0);
const pii ee = make_pair(1, 1);

inline pii _sum(const pii &p1, const pii &p2) {
    return make_pair(
        p1.first + p2.first < mod1 ? p1.first + p2.first : p1.first + p2.first - mod1,
        p1.second + p2.second < mod2 ? p1.second + p2.second : p1.second + p2.second - mod2
    );
}

inline pii _sub(const pii &p1, const pii &p2) {
    return make_pair(
        p1.first >= p2.first ? p1.first - p2.first : p1.first - p2.first + mod1,
        p1.second >= p2.second ? p1.second - p2.second : p1.second - p2.second + mod2
    );
}

inline pii _mul(const pii &p1, const pii &p2) {
    return make_pair(
        (1ll * p1.first * p2.first) % mod1,
        (1ll * p1.second * p2.second) % mod2
    );
}

inline pii _binpow(pii x, int pw) {
    pii res = ee;
    pii tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = _mul(res, tmp);
        }
        pw >>= 1;
        tmp = _mul(tmp, tmp);
    }
    return res;
}

const int N = 5005;

int n;
int h[N];
int res[N];
int L[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        if(x == 0) {
            h[i] = 0;
            continue;
        }
        if(x < 0) {
            h[i] = -1;
            x = -x;
        }else {
            h[i] = +1;
        }
        unordered_set< int > pr;
        for(int y = 2;y * y <= x;y++) {
            if(x % y == 0) {
                if(pr.count(y)) {
                    pr.erase(y);
                }else {
                    pr.insert(y);
                }
                x /= y;
                y--;
            }
        }
        if(x > 1) {
            if(pr.count(x)) {
                pr.erase(x);
            }else {
                pr.insert(x);
            }
        }
        for(int p : pr) {
            h[i] *= p;
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = i - 1;j >= 1;j--) {
            if(h[i] == h[j]) {
                L[i] = j;
                break;
            }
        }
    }

    for(int l = 1;l <= n;l++) {
        int k = 0;
        for(int r = l;r <= n;r++) {
            if(h[r] && L[r] < l) {
                k++;
            }
            res[max(1, k)]++;
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", res[i]);
    }

    printf("\n");

    return 0;
}