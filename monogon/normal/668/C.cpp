
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int n;
long double mx[N], mn[N], x[N], y[N];
const long double EPS = 1e-12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> mx[i];
        mx[i] += mx[i - 1];
    }
    rep(i, 1, n + 1) cin >> mn[i];
    for(int i = n; i >= 0; i--) mn[i] += mn[i + 1];
    rep(i, 1, n + 1) {
        long double A = mx[i];
        long double B = 1 + A - mn[i + 1];
        assert(B * B - 4 * A > -EPS);
        x[i] = (B + sqrtl(max((long double) 0.0, B * B - 4 * A))) / 2.0;
        y[i] = B - x[i];
        if(x[i] < x[i - 1] - EPS || y[i] < y[i - 1] - EPS) swap(x[i], y[i]);
    }
    cout << fixed << setprecision(8);
    rep(i, 1, n + 1) {
        cout << x[i] - x[i - 1] << ' ';
    }
    cout << '\n';
    rep(i, 1, n + 1) {
        cout << y[i] - y[i - 1] << ' ';
    }
    cout << '\n';
}