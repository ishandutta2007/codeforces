#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest; cin >> ntest;
    while (ntest--) {
        int a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        if (a > b) swap(a, b);
        while (b <= n) {
            int c = a + b;
            a = b; b = c;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}