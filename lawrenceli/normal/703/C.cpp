#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 10100;

int n, w, v, u;
int x[maxn], y[maxn];

bool good() {
    for (int i = 0; i < n; i++)
        if (ll(x[i]) * u < ll(y[i]) * v)
            return 0;
    return 1;
}

ld gett() {
    ld ret = ld(w) / u;
    for (int i = 0; i < n; i++)
        ret = max(ret, ld(x[i]) / v + ld(w - y[i]) / u);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> w >> v >> u;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    if (good()) {
        cout << fixed << setprecision(15) << ld(w) / u << '\n';
        return 0;
    }

    cout << fixed << setprecision(15) << gett() << '\n';
}