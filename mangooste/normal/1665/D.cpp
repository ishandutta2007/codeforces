#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests;
    cin >> tests;
    while (tests--) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            cout << "? " << (1 << i) - ans << " " << (1 << i) + (1 << (i + 1)) - ans << endl;
            int res;
            cin >> res;
            if (res == (1 << (i + 1))) ans += (1 << i);
        }
        cout << "! " << ans << endl;
    }
}