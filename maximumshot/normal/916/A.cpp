#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int x;
    cin >> x;

    int hh, mm;

    cin >> hh >> mm;

    int t0 = hh * 60 + mm;

    int res = inf;

    for(int h = 0;h < 24;h++) {
        for(int m = 0;m < 60;m++) {
            int t = h * 60 + m;
            int ok = 0;
            if(h % 10 == 7) ok = 1;
            if(h / 10 == 7) ok = 1;
            if(m % 10 == 7) ok = 1;
            if(m / 10 == 7) ok = 1;
            if(!ok) continue;
            int d = t <= t0 ? t0 - t : 24 * 60 - t + t0;
            if(d % x) continue;
            res = min(res, d / x);
        }
    }

    cout << res << "\n";

    return 0;
}