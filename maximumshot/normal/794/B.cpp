#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    double n, h;

    cin >> n >> h;

    double s0 = h / (2.0 * n);

    double cur_h = 0.0;
    double cur_a = 1.0;

    cout.precision(10);
    cout << fixed;

    vec< double > res;

    for(int i = 0;i < n - 1;i++) {
        double A = cur_a / (h - cur_h);
        double B = -2.0 * cur_a;
        double C = 2 * s0;
        double D2 = B * B - 4.0 * A * C;
        if(D2 < 0) D2 = 0;
        double h1 = (-B + sqrt(D2)) / (2.0 * A);
        double h2 = (-B - sqrt(D2)) / (2.0 * A);
        double h0;
        if(h1 >= 0 && h1 <= h - cur_h) {
            h0 = h1;
        }else {
            h0 = h2;
        }
        double b = cur_a - cur_a * h0 / (h - cur_h);
        cur_h += h0;
        res.push_back(h - cur_h);
        cur_a = b;
    }

    reverse(ALL(res));

    for(double x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}