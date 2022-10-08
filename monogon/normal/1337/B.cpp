
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, x, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> n >> m;
        while(n--) {
            if(x / 2 + 10 < x) x = x / 2 + 10;
        }
        cout << (x <= 10 * m ? "YES" : "NO") << '\n';
    }
}