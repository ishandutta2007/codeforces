#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1e-10;

int R, D;

bool good(int x, int y, int r) {
    ld dist = sqrt(x * x + y * y);
    if (dist - r + eps >= R - D && dist + r - eps <= R) return 1;
    return 0;
}

int main() {
    cin >> R >> D;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        if (good(x, y, r)) ans++;
    }
    cout << ans;
}