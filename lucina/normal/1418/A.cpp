#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int64_t x, y, k;
        cin >> x >> y >> k;
        int64_t need_stick = y * k + k - 1;
        int64_t f = (need_stick + x - 2) / (x - 1);
        cout << f + k << '\n';
    }
}
/*
    ZZZZZZZ
*/