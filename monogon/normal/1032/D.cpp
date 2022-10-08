
#include <bits/stdc++.h>

#define ll long long
#define PT complex<double>
#define x real()
#define y imag()
#define dot(a, b) (conj(a) * b).x
#define cross(a, b) (conj(a) * (b)).y
using namespace std;

istream &operator>>(istream &is, PT &p) {
    double X, Y;
    is >> X >> Y;
    p = PT(X, Y);
    return is;
}

const double EPS = 1e-10;
ll a, b, c;
double A, B, C;
PT p1, p2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> p1 >> p2;
    A = a, B = b, C = c;
    double M = abs(p1.x - p2.x) + abs(p1.y - p2.y);
    cout << fixed << setprecision(8);
    if(b == 0 || a == 0) {
        cout << M << endl;
        return 0;
    }
    PT pp1[2] = {PT(p1.x, (-A * p1.x - C) / B), PT((-B * p1.y - C) / A, p1.y)};
    PT pp2[2] = {PT(p2.x, (-A * p2.x - C) / B), PT((-B * p2.y - C) / A, p2.y)};
    for(int i = 0; i < 4; i++) {
        M = min(M, abs(p1 - pp1[i / 2]) + abs(pp1[i / 2] - pp2[i & 1]) + abs(pp2[i & 1] - p2));
    }
    cout << M << endl;
}