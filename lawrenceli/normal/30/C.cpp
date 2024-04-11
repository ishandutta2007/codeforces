#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 1005;

int n;

struct data {
    ll x, y, t;
    double p;

    bool operator<(const data& d) const {
        return t < d.t;
    }
} arr[MAXN];

double dp[MAXN];

ll dist(data d1, data d2) { //distance squared
    return (d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y);
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i].x >> arr[i].y >> arr[i].t >> arr[i].p;

    sort(arr, arr + n);

    double ans = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++)
            if (dist(arr[i], arr[j]) <= (arr[i].t - arr[j].t) * (arr[i].t - arr[j].t))
                dp[i] = max(dp[i], dp[j]);

        dp[i] += arr[i].p;
        ans = max(ans, dp[i]);
    }

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}