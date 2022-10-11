#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n;
map<pair<int, int>, int> ans[2];

void normalize(int& x, int& y) {
    int g = __gcd(x, y);
    x /= g; y /= g;
    if (y < 0 || (y == 0 && x < 0)) {
        x = -x;
        y = -y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        long long tot = 0;
        ans[0].clear(); ans[1].clear();
        cin >> n;
        while (n--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int x = c - a, y = d - b;
            normalize(x, y);
            bool typ = (a < c || (a == c && b < d));
            tot += ans[typ ^ 1][{x, y}];
            ans[typ][{x, y}]++;
        }
        cout << tot << '\n';
    }
}