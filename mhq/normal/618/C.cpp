#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int n;
ll x[maxN], y[maxN];
ll dist(int i, int j) {
    return (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int a = -1;
    for (int i = 2; i <= n; i++) {
        if (a == -1 || dist(1, a) > dist(1, i)) a = i;
    }
    int b = -1;
    for (int i = 2; i <= n; i++) {
        if ((x[i] - x[a]) * (y[i] - y[1]) == (y[i] - y[a]) * (x[i] - x[1])) continue;
        if (b == -1 || dist(1, b) > dist(1, i)) b = i;
    }
    cout << 1 << " " << a << " " << b;
    return 0;
}