#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

double v;
double f(double c, double m, double p) {
    if (c <= 1e-10) {
        c = 0;
    }
    if (m <= 1e-10) {
        m = 0;
    }
    if (c == 0 && m == 0) return 1;
    if (c == 0) {
        return 1 + m * (m <= v ? 1 : f(0, m - v, p + v));
    }
    if (m == 0) {
        return 1 + c * (c <= v ? 1 : f(c - v, 0, c + v));
    }
    double ret = 1;
    ret += c * (c <= v ? f(0, m + c / 2, p + c / 2) : f(c - v, m + v / 2, p + v / 2));
    ret += m * (m <= v ? f(c + m / 2, 0, p + m / 2) : f(c + v / 2, m - v, p + v / 2));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(16);
    int tt;
    cin >> tt;
    while(tt--) {
        double c, m, p;
        cin >> c >> m >> p >> v;
        cout << f(c, m, p) << '\n';
    }
}