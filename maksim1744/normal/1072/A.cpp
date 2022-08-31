/*
    21.10.2018 11:10:51
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int w, h, k;
    cin >> w >> h >> k;
    int s = (w - 1 + h - 1) * 2;
    int ans = s;
    for (int i = 0; i < k - 1; ++i) {
        s -= 16;
        ans += s;
    }
    cout << ans << '\n';
    return 0;
}