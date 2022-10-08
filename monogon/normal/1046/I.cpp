
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

#define pt complex<long double>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

istream& operator>>(istream &is, pt &p) {
    int X, Y;
    is >> X >> Y;
    p = pt(X, Y);
    return is;
}

const long double EPS = 1e-9;

pt pjseg(pt a, pt b, pt p) {
    b -= a, p -= a;
    if(abs(b) < EPS) return a;
    return a + b * clamp((p / b).x, (long double) 0.0, (long double) 1.0);
}

int n, d1, d2, ax, ay, bx, by;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d1 >> d2;
    int ans = 0;
    pt A, B;
    cin >> A >> B;
    pt p = B - A;
    bool away = true;
    if(abs(p) < d1 + EPS) {
        ans++;
        away = false;
    }
    if(abs(p) > d2 + EPS) away = true;
    rep(i, 1, n) {
        pt a, b;
        cin >> a >> b;
        b -= a;
        if(away && abs(pjseg(p, b, pt(0))) < d1 + EPS) {
            away = false;
            ans++;
        }
        p = b;
        if(abs(p) > d2 + EPS) away = true;
    }
    cout << ans << '\n';
}