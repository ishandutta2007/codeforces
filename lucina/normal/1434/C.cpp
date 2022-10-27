#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int64_t solve() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b * c) {
        return -1;
    }

    int64_t k = 1 + (a / (b * d));

    return a * k - k * (k - 1) / 2 * b * d;
}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ;T -- ;) {
        cout << solve() << '\n';
    }
}
/*
    Good Luck
        -Lucina
*/