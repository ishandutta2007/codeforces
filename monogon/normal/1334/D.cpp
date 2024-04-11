
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 1 2 1 3 1 4 1 ... n (answer for 2..n) 1

// on n = 3:
// 1 2 1 3 2 3 1

int t;
ll n, l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> l >> r;
        l--; r--;
        ll idx = 0;
        int st = 1;
        for(int i = n; i > 0; i--) {
            if(idx + 2 * (n - st) <= l) {
                idx += 2 * (n - st);
                st++;
            }
            else break;
        }
        for(ll i = l; i <= r; i++) {
            if(i >= n * (n - 1)) {
                cout << 1 << " ";
                continue;
            }
            if(idx + 2 * (n - st) <= i) {
                idx += 2 * (n - st);
                st++;
            }
            if((i - idx) % 2 == 0) {
                cout << st << " ";
            }else {
                cout << st + (i - idx + 1) / 2 << " ";
            }
        }
        cout << "\n";
    }
}