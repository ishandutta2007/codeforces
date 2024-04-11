
#pragma GCC optimize ("Ofast")
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// for a fixed X,
// what radius do we need for circle to contain (x_i, y_i)
// assume all y_i > 0. If two y of different signs, impossible
// (x_i - X)^2 + (y_i - r)^2 = r^2
// x_i ^2 - 2 X x_i + X^2 + y_i^2 - 2 r y_i = 0
// r (2 y_i) = (x_i - X)^2 + y_i^2
// r = [ (x_i - X)^2 + y_i^2 ] / (2 y_i)
// we can find radius for fixed X.
// ternary search

const int N = 1e5 + 5;
const double EPS = 1e-7;
int n;
ll x[N], y[N];

double check(double X) {
    double r = 0;
    rep(i, 0, n) {
        r = max(r, (x[i] - X) * (x[i] - X) / (2 * y[i]) + y[i] * 0.5);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    bool flip = false;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        if(flip) y[i] = -y[i];
        if(y[i] < 0 && i > 0) {
            cout << "-1\n";
            return 0;
        }else if(y[i] < 0) {
            flip = true;
            y[i] = -y[i];
        }
    }
    double L = -1e7, R = 1e7;
    while(R - L > EPS) {
        double m1 = L + (R - L) / 3;
        double m2 = L + 2 * (R - L) / 3;
        if(check(m1) < check(m2)) {
            R = m2;
        }else {
            L = m1;
        }
    }
    cout << fixed << setprecision(8);
    cout << check(L) << '\n';
}