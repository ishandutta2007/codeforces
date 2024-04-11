#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int s, x1, x2;

    cin >> s >> x1 >> x2;

    int t1, t2;

    cin >> t1 >> t2;

    int p, d;

    cin >> p >> d;

    int res = abs(x1 - x2) * t2;

    if(t2 <= t1) {
        cout << res << "\n";
        return 0;
    }

    int time = 0, dd;

    if(x1 < p) {
        if(d == -1) {
            time += (p - x1) * t1;
        }else {
            time += (s - p + s - x1) * t1;
        }
        dd = -1;
    }else if(x1 > p) {
        if(d == 1) {
            time += (x1 - p) * t1;
        }else {
            time += (p + x1) * t1;
        }
        dd = 1;
    }else {
        dd = d;
    }

    p = x1;
    x1 = x2;
    d = dd;

    if(x1 < p) {
        if(d == -1) {
            time += (p - x1) * t1;
        }else {
            time += (s - p + s - x1) * t1;
        }
        dd = -1;
    }else {
        if(d == 1) {
            time += (x1 - p) * t1;
        }else {
            time += (p + x1) * t1;
        }
        dd = 1;
    }

    cout << min(res, time) << "\n";

    return 0;
}