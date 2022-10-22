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
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(105);
        for (int x, i = 0; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }
        for (int x, i = 0; i < m; i++) {
            cin >> x;
            cnt[x]++;
        }
        int res = 0;
        for (int x : cnt)
            res += x >= 2;
        cout << res << "\n";
    }

    return 0;
}