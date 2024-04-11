#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int res = 10;
        for (int mask = 0; mask < (1 << 10); mask++) {
            int ok = 1;
            for (int i = 0; i < 10; i++) {
                if (s[i] == '1' && !((1 << i) & mask)) {
                    ok = 0;
                    break;
                }
                if (s[i] == '0' && ((1 << i) & mask)) {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                continue;
            int cur = 0, x = 0, y = 0, rx = 5, ry = 5;
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) rx--;
                else ry--;
                if ((1 << i) & mask) {
                    if (i % 2 == 0) {
                        x++;
                    } else {
                        y++;
                    }
                }
                cur++;
                if (x > y + ry || y > x + rx) {
                    break;
                }
            }
            res = min(res, cur);
        }
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}