/*
    28.12.2018 17:45:26
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    vector< int > a;
    vector< int > b;
    for (int i = 3; i <= 180; ++i) {
        if (180 % i == 0) {
            a.push_back(180 / i);
            b.push_back(i);
        }
    }
    for (int test = 0; test < tests; ++test) {
        int ang;
        cin >> ang;
        int ans = 1000000000;
        for (auto k : a) {
            if (ang % k == 0) {
                if (ang / k >= 180 / k - 1) {
                    ans = min(ans, 180 / k * 2);
                } else {
                    ans = min(ans, 180 / k);
                }
            }
        }
        if (ans == 1000000000) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}