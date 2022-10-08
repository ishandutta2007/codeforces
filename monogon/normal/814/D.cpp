
#define _USE_MATH_DEFINES
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
    ll X, Y;
    is >> X >> Y;
    p = pt(1.0 * X, 1.0 * Y);
    return is;
}

const int N = 1005;
int n;
ll r[N];
pt p[N];
const long double EPS = 1e-12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> p[i] >> r[i];
    }
    double ans = 0;
    rep(i, 0, n) {
        int cnt = 0;
        rep(j, 0, n) {
            if(i == j) continue;
            if(abs(p[i] - p[j]) + r[i] < r[j] + EPS) {
                cnt++;
            }
        }
        if(cnt % 2 == 1 || cnt == 0) {
            ans += M_PI * r[i] * r[i];
        }else {
            ans -= M_PI * r[i] * r[i];
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
}