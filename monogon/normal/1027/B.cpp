
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll n, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    while(q--) {
        cin >> x >> y;
        x--; y--;
        ll ans = 0;
        if((x ^ y) & 1) {
            ans = (n * n + 1) / 2;
            if(x % 2 == 0) y--;
            y /= 2;
            ans += n * (x / 2) + y + 1;
            if(x & 1) {
                ans += (n / 2);
            }
        }else {
            y -= (x & 1);
            y /= 2;
            ans = n * (x / 2) + y + 1;
            if(x & 1) {
                ans += ((n + 1) / 2);
            }
        }
        cout << ans << '\n';
    }
}