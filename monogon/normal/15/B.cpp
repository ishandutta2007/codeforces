
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct rect {
    ll x1, y1, x2, y2;
    ll area() {
        return max(0LL, x2 - x1 + 1) * max(0LL, y2 - y1 + 1);
    }
};

ll t, n, m, x[2], y[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> x[0] >> y[0] >> x[1] >> y[1];
        rect R1 = {max(1LL, x[0] - (x[1] - 1)), max(1LL, y[0] - (y[1] - 1)),
                   min(n, x[0] + (n - x[1])), min(m, y[0] + (m - y[1]))};
        rect R2 = {max(1LL, x[1] - (x[0] - 1)), max(1LL, y[1] - (y[0] - 1)),
                   min(n, x[1] + (n - x[0])), min(m, y[1] + (m - y[0]))};
        rect isect = {max(R1.x1, R2.x1), max(R1.y1, R2.y1), min(R1.x2, R2.x2), min(R1.y2, R2.y2)};
        cout << (n * m - R1.area() - R2.area() + isect.area()) << endl;
    }
}