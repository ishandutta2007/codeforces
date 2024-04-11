#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << "First" << endl;

    ll mx = max({a, b, c});
    ll mn = min({a, b, c});

    int mn_i = a == mn ? 1 : b == mn ? 2 : 3;
    int mx_i = a == mx ? 1 : b == mx ? 2 : 3;

    auto ask = [&](ll y) -> int {
        cout << y << endl;
        int i;
        cin >> i;
        if (i < 1 || i > 3)
            exit(0);
        if (i == 1)
            a += y;
        else if (i == 2)
            b += y;
        else
            c += y;
        return i;
    };

    if (ask(3 * mx - (a + b + c)) == mx_i) {
        mx = max({a, b, c});
        mn = min({a, b, c});
        ask(3 * mx - (a + b + c));
    }

    mx = max({a, b, c});
    mn = min({a, b, c});

    ll mx2 = a + b + c - mx - mn;

    ask(mx - mx2);

    return 0;
}