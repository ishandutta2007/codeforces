#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K; double lo, hi, L, v1, v2, v;

bool can(double t) {
    double T = (L - t * v1) / v;
    double cur = T * v1 / (v2 + v1) * 2 * v2 * (N - 1);
    if (cur + T * v2 > L) return 0;
    return 1;
}

int main(void) {
    cin >> N >> L >> v1 >> v2 >> K;
    N = (N - 1) / K + 1;
    v = v2 - v1;
    double l = 1.0 * L / v2, r = 1.0 * L / v1;
    lo = l; hi = r;
    ff(rep, 1, 10000) {
        double m = (l + r) / 2;
        if (can(m)) r = m; else l = m;
    }
    cout << setprecision(9) << fixed << l << endl;
    return 0;
}