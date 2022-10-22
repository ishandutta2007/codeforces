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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                res = max(res, 2 * max(i + 1, n - i));
            }
        }
        cout << res << "\n";
    }

    return 0;
}