#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int , int > pii;

int const inf = 1000 * 1000 * 1000;

bool solve() {

    int n, w, v, u, x, y;

    scanf("%d %d %d %d", &n, &w, &v, &u);

    double mx = 0, mn = 1e18;

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &x, &y);
        mx = max(mx, 1.0 * x / v - 1.0 * y / u);
        mn = min(mn, 1.0 * x / v - 1.0 * y / u);
    }

    cout.precision(10);
    cout << fixed;

    if(mn >= 0) {
        cout << 1.0 * w / u << '\n';
    }else {
        cout << 1.0 * w / u + mx << '\n';
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}