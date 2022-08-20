/*
    19.10.2018 16:51:12
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        int ans = 1;
        while (a > 0) {
            if (a % 2) {
                ans *= 2;
            }
            a /= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}