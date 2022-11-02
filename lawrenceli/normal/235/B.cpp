#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

const int MAXN = 100100;

int n;
double p[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> p[i];

    double ans = 0, cur = 0;

    for (int i=0; i<n; i++) {
        cur = p[i] * (1 + cur);
        ans += 2*cur;
    }

    for (int i=0; i<n; i++) ans -= p[i];

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}