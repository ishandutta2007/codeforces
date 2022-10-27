#include<bits/stdc++.h>
using namespace std;
const int MOD = 32768;
/***
    11100111111100 -> can use 4 operations
*/

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int a;
        cin >> a;
        int ans = a % MOD ? 16 : 0;
        int s = 0;
        while (a % MOD) {
            ans = min(ans, 15 - __lg(a & -a) + s);
            s += a & -a;
            a += a & -a;
        }
        cout << min(ans, s) << '\n';
    }
}