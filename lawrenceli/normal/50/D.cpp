#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXN = 105;
const double EPS = 1e-9;

int n, k;
double e;
int px0, py0;
int x[MAXN], y[MAXN];
double dp[MAXN][2];

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double prob(int ind, double rad) {
    double _dist = dist(x[ind], y[ind], px0, py0);
    if (_dist <= rad) return 1;
    return exp(1 - pow(_dist, 2) / pow(rad, 2));
}

bool check(double rad) {
    for (int i=0; i<MAXN; i++) dp[i][0] = dp[i][1] = 0;
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        double p = prob(i, rad);
        for (int j=0; j<MAXN-1; j++) {
            dp[j+1][1] += dp[j][0] * p;
            dp[j][1] += dp[j][0] * (1-p);
        }

        for (int j=0; j<MAXN; j++)
            dp[j][0] = dp[j][1], dp[j][1] = 0;
    }

    double sum = 0;
    for (int i=0; i<k; i++) sum += dp[i][0];
    return sum < e;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    int _e; cin >> _e;
    e = 1. * _e / 1000;
    cin >> px0 >> py0;
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];

    double lo = 0, hi = 5000;

    while (abs(hi - lo) > 2*EPS) {
        double mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + EPS;
    }

    cout << fixed << setprecision(10) << lo << endl;
    return 0;
}