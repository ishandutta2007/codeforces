#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const ll LONGINF = 4e18;

pair<double, double> operator-(pair<double, double> a, pair<double, double> b) {
    return {a.first - b.first, a.second - b.second};
};

double abs(pair<double, double> a) {
    return sqrt(a.first * a.first + a.second * a.second);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double> > v;
    double ans = 1e100;
    for(int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    for(int i = 0; i < n; ++i) {
        auto a = v[i], b = v[(i + 1) % n], c = v[(i + 2) % n];
        b = b - a;
        c = c - a;
        ans = min(ans, abs(c.first * b.second - c.second * b.first) / abs(c));
    }
    printf("%.10lf\n", ans / 2);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();

    return 0;
}