#include <bits/stdc++.h>

using namespace std;



int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int ans1 = abs(x - y) * t1;
    int ans2 = abs(z - x) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
    cerr << ans1 << ' ' << ans2 << endl;
    cout << (ans1 < ans2 ? "NO" : "YES") << endl;
    return 0;
}