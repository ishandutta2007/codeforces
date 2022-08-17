#include <bits/stdc++.h>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define left privet6

using namespace std;
typedef long long ll;
typedef long double ld;

const long long max_n = 1011, log_n = 32, max_m = 111, mod = 1000000007, inf = 1000000009;

int n;
pair<int, int> p[max_n];

ll sqr(ll a) {
    return a * a;
}

ld get_dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(sqr(a.F - b.F) + sqr(a.S - b.S));
}

ld get_dist(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    ll aa = c.S - b.S, bb = b.F - c.F;
    ll cc = -aa * b.F - bb * b.S;
    return abs(aa * a.F + bb * a.S + cc) / sqrt(sqr(aa) + sqr(bb));
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i =0 ; i < n; ++i) {
        cin >> p[i].F >> p[i].S;
    }
    p[n] = p[0];
    p[n + 1] = p[1];
    ld mx = 1000000000000000;
    for (int i = 1; i <= n; ++i) {
        mx = min(mx, min(get_dist(p[i], p[i - 1], p[i + 1]),
                         min(get_dist(p[i], p[i - 1]),
                             get_dist(p[i], p[i + 1]))));
        //cout << get_dist(p[i], p[i - 1], p[i + 1]) << "     " << get_dist(p[i], p[i - 1]) << "     " << get_dist(p[i], p[i + 1]) << endl;
    }
    printf("%.9f\n", (double)(mx / 2));
    return 0;
}