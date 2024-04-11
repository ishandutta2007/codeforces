#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        ans = max(ans, s + max(0, t - s + f));
    }
    cout << ans << '\n';
}