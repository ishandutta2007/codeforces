#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int n;
int ge = -inf, le = inf;
int cur;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        if (d == 1) ge = max(ge, 1900 - cur);
        else le = min(le, 1899 - cur);
        cur += c;
    }

    //cout << ge << ' ' << le << endl;

    if (ge > le) cout << "Impossible\n";
    else {
        if (le == inf) cout << "Infinity\n";
        else cout << le + cur << '\n';
    }
}