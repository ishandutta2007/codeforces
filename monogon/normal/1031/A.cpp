
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int w, h, k;
    cin >> w >> h >> k;
    int ans = 0;
    for(int i = 0; i < k; i++) {
        ans += 2 * w + 2 * h - 4;
        w -= 4;
        h -= 4;
    }
    cout << ans << '\n';
}