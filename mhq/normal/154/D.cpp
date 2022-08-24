#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x1, x2, a, b;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> x1 >> x2 >> a >> b;
    if (x1 + a <= x2 && x2 <= x1 + b) {
        cout << "FIRST" << '\n';
        cout << x2;
        return 0;
    }
    ll d = x2 - x1;
    bool swapped = false;
    if (b < 0) {
        ll nb = -a;
        ll na = -b;
        b = nb;
        a = na;
        d = -d;
        swapped = true;
    }
    if (a <= 0) {
        cout << "DRAW";
        return 0;
    }
    if (d < 0) {
        cout << "DRAW";
        return 0;
    }
    ll res = d % (b + a);
    if (res == 0) {
        cout << "SECOND";
        return 0;
    }
    if ((res <= a - 1) || (res >= b + 1)) {
        cout << "DRAW";
        return 0;
    }
    cout << "FIRST" << '\n';
    if (!swapped) {
        cout << x1 + res;
    }
    else {
        cout << x1 - res;
    }
    return 0;
}