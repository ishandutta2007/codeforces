#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = 1000000000;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (size_t i = 0; i != T; ++i) {
        ll a, b;
        cin >> a >> b;
        ll n; cin >> n;

        if (n % 3 == 0) {
            cout << a << '\n';
        } else if (n % 3 == 1) {
            cout << b << '\n';
        } else {
            ll c = b ^ a;
            cout << c << '\n';
        }
    }
}