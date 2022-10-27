#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int d(int x, int y, int z) {
    return abs(x + z - 2 * y);
}
int a[3];

void solve() {
    for (int i = 0 ; i < 3 ; ++ i)
        cin >> a[i];
    cout << min(1, (a[0] + a[1] + a[2]) % 3) << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Missing the contest. :3
*/