
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, a, b, c, d, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> k;
        for(int i = 0; i <= k; i++) {
            if(i * c >= a && (k - i) * d >= b) {
                cout << i << " " << (k - i) << endl;
                goto endloop;
            }
        }
        cout << -1 << endl;
        endloop:;
    }
}