
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

typedef long double ftype;

// for some linear combination (u, v)
// minimize max(|a + c u|, |b + c v|)
// with scalar c

// a + c u = b + c v => c (v - u) = a - b => c = (a - b) / (v - u)
// a + c u = -b - c v => c (u + v) = -a - b => c = -(a + b) / (u + v)

ftype a, b, c, d;
const int N = 1e4;
ftype ans = DBL_MAX;

ftype dogdare(ftype angle) {
    ftype u = cos(angle);
    ftype v = sin(angle);
    ftype x = 0;
    if(abs(u - v) < 1e-11) {
        x = max(max(abs(a - u * (a + b) / (v + u)), abs(b - v * (a + b) / (v + u))),
                max(abs(c - u * (c + d) / (v + u)), abs(d - v * (c + d) / (v + u))));
    }else if(abs(u + v) < 1e-11) {
        x = max(max(abs(a + u * (a - b) / (v - u)), abs(b + v * (a - b) / (v - u))),
                max(abs(c + u * (c - d) / (v - u)), abs(d + v * (c - d) / (v - u))));
    }else {
        x = max(min(max(abs(a + u * (a - b) / (v - u)), abs(b + v * (a - b) / (v - u))),
                    max(abs(a - u * (a + b) / (v + u)), abs(b - v * (a + b) / (v + u)))),
                min(max(abs(c + u * (c - d) / (v - u)), abs(d + v * (c - d) / (v - u))),
                    max(abs(c - u * (c + d) / (v + u)), abs(d - v * (c + d) / (v + u)))));
    }
    ans = min(ans, x);
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cin >> a >> b >> c >> d;
    rep(i, 0, N) {
        ftype L = i * M_PI / N, R = (i + 1) * M_PI / N;
        while(R - L > 1e-18) {
            ftype M1 = L + (R - L) / 3;
            ftype M2 = L + 2 * (R - L) / 3;
            if(dogdare(M1) < dogdare(M2)) {
                R = M2;
            }else {
                L = M1;
            }
        }
    }
    cout << ans << '\n';
}