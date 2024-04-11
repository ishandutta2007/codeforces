
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

#define ftype long double
#define pt complex<ftype>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

istream& operator>>(istream &is, pt &p) {
    ll X, Y;
    is >> X >> Y;
    p = pt(X, Y);
    return is;
}

const int N = 1005;
int n;
pt p[N];

pt pjline(pt a, pt b, pt p) {
    b -= a, p -= a;
    return a + b * (p / b).x;
}

ftype D = 1e18;

void solve(pt a, pt b, pt c) {
    D = min(D, 0.5 * abs(a - pjline(b, c, a)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> p[i];
    }
    rep(i, 0, n) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;
        solve(p[i], p[j], p[k]);
        solve(p[j], p[k], p[i]);
        solve(p[k], p[i], p[j]);
    }
    cout << fixed << setprecision(8);
    cout << D << '\n';
}