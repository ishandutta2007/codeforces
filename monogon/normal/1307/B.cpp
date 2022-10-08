
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
ll x, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll d = 0;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            cin >> a;
            if(a == x) {
                flag = true;
            }
            d = max(d, a);
        }
        if(flag) {
            cout << 1 << endl;
        }else {
            cout << max(2LL, (x + d - 1) / d) << endl;
        }
    }
}