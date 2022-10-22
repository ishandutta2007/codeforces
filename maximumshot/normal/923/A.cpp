#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vec< int > f(int x) {
    vec< int > res;
    for(int p = 2;p * p <= x;p++) {
        if(x % p) continue;
        res.push_back(p);
        x /= p;
        p--;
    }
    if(x > 1) {
        res.push_back(x);
    }
    sort(ALL(res));
    res.resize(unique(ALL(res)) - res.begin());
    return res;
}

const int X = 1e6 + 5;

int pr[X];

int get(int p, int x) {
    int k = (x + p - 1) / p;
    return p * k;
}

int main() {

    fill(pr, pr + X, 1);
    pr[0] = pr[1] = 0;

    for(int p = 2;p * p < X;p++) {
        if(!pr[p]) continue;
        for(int x = p * p;x < X;x += p) {
            pr[x] = 0;
        }
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int x2;

    cin >> x2;

    int res = inf;
    vec< int > ar = f(x2);

    for(int p0 = 2;p0 < X;p0++) {
        if(!pr[p0]) continue;
        for(int x1 = 2 * p0;x1 < X;x1 += p0) {
            int k = x1 / p0;
            for(int p1 : ar) {
                if(p1 >= x1) continue;
                if(get(p1, x1) == x2) {
                    res = min(res, x1 - p0 + 1);
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}