#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

int calc(int i) {
    if (i == 1 || i == n) return 0;
    if ((a[i] < min(a[i - 1], a[i + 1])) || (a[i] > max(a[i - 1], a[i + 1])))
        return 1;
    else return 0;
}

const int delta[11] = {-5, -4, -3, -2, -1, 0, +1, +2, +3, +4, +5};

void solve() {
    cin >> n;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

   // if (n <= 3) return cout << 0 << '\n', void();

    int ans = 0;

    for (int i = 2 ; i < n ; ++ i) {
        ans += calc(i);
    }

    int res = ans;
    vector <int> f;

    for (int i = 2 ; i < n ; ++ i) {
        int cur = ans - calc(i) - calc(i - 1) - calc(i + 1);
        int bef = a[i];
        f.clear();
        for (int j = 0 ; j < 11 ; ++ j) f.push_back(a[i - 1] + delta[j]), f.push_back(a[i + 1] + delta[j]), f.push_back(bef + delta[j]);
        f.push_back(1e9 + 1), f.push_back(0);
        for (int bar : f) {
            a[i] = bar;
            res = min(res, cur + calc(i - 1) + calc(i) + calc(i + 1));

        }
        a[i] = bef;
    }

    if (calc(2) || calc(n - 1)) res = min(res, ans - 1);

    cout << max(res, 0) << '\n';

}

/**


*/

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}