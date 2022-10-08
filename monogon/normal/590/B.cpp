
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

#define pt complex<double>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

const double EPS = 1e-9;
const pt I(0, 1);

istream &operator>>(istream &is, pt &p) {
    double X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

pt p1, p, v, w;
double vmax, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> p1 >> p >> vmax >> t >> v >> w;
    p -= p1;
    v = -v; w = -w;
    double A = norm(v) - vmax * vmax;
    double B = 2 * dot(p, v);
    double C = norm(p);
    double D = B * B - 4 * A * C;
    double T = (-B + sqrt(D)) / (2 * A);
    if(T < -EPS) {
        T = (-B - sqrt(D)) / (2 * A);
    }
    cout << fixed << setprecision(9);
    if(T < t + EPS) {
        cout << T << '\n';
        return 0;
    }
    p += t * (v - w);
    A = norm(w) - vmax * vmax;
    B = 2 * dot(p, w);
    C = norm(p);
    D = B * B - 4 * A * C;
    T = (-B + sqrt(D)) / (2 * A);
    if(T < t - EPS) {
        T = (-B - sqrt(D)) / (2 * A);
    }
    cout << T << '\n';
}