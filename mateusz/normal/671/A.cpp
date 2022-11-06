#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const long double INF = 1e18;

int n;
int aX, aY, bX, bY, tX, tY;
int x[N], y[N];

long double dist(int i, int xx, int yy) {
    return sqrt((long long)(x[i] - xx) * (x[i] - xx) + (long long)(y[i] - yy) * (y[i] - yy));
}

int main() {

    ios_base::sync_with_stdio(0);

    cin >> aX >> aY >> bX >> bY >> tX >> tY;
    cin >> n;

    long double totalDist = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        totalDist += 2 * dist(i, tX, tY);
    }

    long double ans = INF;
    long double bestDistA = 0;
    long double bestDistB = 0;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, totalDist + min(dist(i, aX, aY) - dist(i, tX, tY) + bestDistB, dist(i, bX, bY) - dist(i, tX, tY) + bestDistA));
        bestDistA = min(bestDistA, dist(i, aX, aY) - dist(i, tX, tY));
        bestDistB = min(bestDistB, dist(i, bX, bY) - dist(i, tX, tY));
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}