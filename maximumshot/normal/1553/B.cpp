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
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int n = (int) s.size();
        int m = (int) t.size();
        int ok = 0;
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<vector<int>> lcp(n + 1, vector<int>(m + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (rs[i] == t[j])
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }
        for (int i = 0; i < n; i++) {
            int pr = 1;
            for (int j = i; j < n && j - i + 1 <= m; j++) {
                pr &= s[j] == t[j - i];
                int rem = m - (j - i + 1);
                if (rem > j + 1)
                    continue;
                if (rem == 0 && pr)
                    ok = 1;
                int k = n - 1 - j;
                if (pr && lcp[k + 1][j - i + 1] >= rem)
                    ok = 1;
            }
            if (ok)
                break;
        }
        cout << (ok ? "YES" : "NO") << "\n";
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