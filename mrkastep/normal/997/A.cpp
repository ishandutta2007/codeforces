#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    s = '1' + s + '1';
    int c = 0;
    int segs = 0;
    for (auto i : s) {
        if (i == '1' && c)
            ++segs, c = 0;
        if (i == '0')
            ++c;
    }
    if (segs == 0) {
        cout << 0 << endl;
        return;
    }
    cout << y + min(x, y) * (segs - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}