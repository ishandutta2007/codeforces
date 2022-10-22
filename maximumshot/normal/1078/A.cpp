#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;

#define vec vector
#define ALL(x) begin(x), end(x)

const ld eps = 1e-9;

ld sqr(ld x) {
    return x * x;
}

ld dist(pdd p1, pdd p2) {
    return sqrt( sqr(p1.first - p2.first) + sqr(p1.second - p2.second) );
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll a, b, c;

    cin >> a >> b >> c;

    ll x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    ld res = std::abs(x1 - x2) + std::abs(y1 - y2);

    vec< pdd > A, B;

    if(b) {
        A.push_back({x1, ld(-c - a * x1) / ld(b)});
        B.push_back({x2, ld(-c - a * x2) / ld(b)});
    }

    if(a) {
        A.push_back({ld(-c - b * y1) / ld(a), y1});
        B.push_back({ld(-c - b * y2) / ld(a), y2});
    }

//    for(pdd p1 : A) {
//        cout << p1.first << " " << p1.second << "\n";
//    }
//    cout << "\n---\n";
//    for(pdd p2 : B) {
//        cout << p2.first << " " << p2.second << "\n";
//    }

    for(pdd p1 : A) {
        for(pdd p2 : B) {
            ld tmp = 0;
            tmp += dist({x1, y1}, p1);
            tmp += dist(p1, p2);
            tmp += dist(p2, {x2, y2});
            res = min(res, tmp);
        }
    }

    cout.precision(20);
    cout << fixed;

    cout << res << "\n";

    return 0;
}