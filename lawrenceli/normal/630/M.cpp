#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll x; cin >> x;
    if (x < 0) x = 360 - ((-x) % 360);
    else x %= 360;

    int best = 1e9, v = 0;
    for (int i = 0; i < 4; i++) {
        int a = min(x, 360 - x);
        if (a < best) best = a, v = i;
        x = (x + 270) % 360;
    }

    cout << v << '\n';
}