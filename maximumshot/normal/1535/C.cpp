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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        vector<vector<int>> cnt(2, vector<int>(2));
        auto check  =[&]() -> bool {
            for (int x = 0; x < 2; x++) {
                int y = x ^ 1;
                if (cnt[0][x] == 0 && cnt[1][y] == 0)
                    return true;
            }
            return false;
        };
        auto upd = [&](int i, int t) {
            if (s[i] == '?')
                return;
            int x = s[i] - '0';
            cnt[x][i % 2] += t;
        };
        ll res = 0;
        for (int j = 0, i = 0; i < n; i++) {
            upd(i, +1);
            while (!check()) {
                upd(j, -1);
                j++;
            }
            res += i - j + 1;
        }
        cout << res << "\n";
    }

    return 0;
}