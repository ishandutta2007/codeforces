#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXN = 21;
const double PI = acos(-1.0);

int n;
double l, r, x[MAXN], y[MAXN], a[MAXN];
bool vis[1<<MAXN];
double dp[1<<MAXN];

double calc(int state) {
    if (vis[state]) return dp[state];
    vis[state] = 1;
    dp[state] = -1e9;

    for (int i=0; i<n; i++) {
        if (state & (1<<i)) {
            double res = calc(state ^ (1<<i));
            double d = sqrt((x[i] - res) * (x[i] - res) + y[i] * y[i]);
            double r = y[i] / d;
            int sgn = 1;
            if (x[i] < res) sgn = -1;
            double dx = d * sin(a[i]) / (sgn * sin(a[i]) * sqrt(1 - r*r) + cos(a[i]) * r);
            if (dx < 0) dx = 1e15;
            dp[state] = max(dp[state], res + dx);
        }
    }

    return dp[state];
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> l >> r;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i] >> a[i];
        a[i] *= PI / 180;
    }

    vis[0] = 1; dp[0] = l;

    cout << setprecision(15) << min(calc((1<<n) - 1), r) - l << '\n';
    return 0;
}