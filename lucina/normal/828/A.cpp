#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, a, b;
int x, y;
int t[nax];
int ans;
int one_free;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> t[i];
        if (t[i] == 1) {
            if (a > 0) -- a;
            else if (b > 0) {
                -- b;
                ++ one_free;
            } else if (one_free > 0) {
                -- one_free;
            } else ++ ans;
        } else {
            if (b > 0) -- b;
            else ans += 2;
        }
    }

    cout << ans << '\n';
}