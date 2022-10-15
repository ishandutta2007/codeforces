//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string x, y;
        cin >> x >> y;
        int pos2;
        for (int i = y.size() - 1; i >= 0; i--) {
            if (y[i] == '1') {
                pos2 = y.size() - i - 1;
                break;
            }
        }
        int ans = 0;
        for (int i = x.size() - pos2 - 1; i >= 0; i--) {
            if (x[i] == '1') {
                break;
            }
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}