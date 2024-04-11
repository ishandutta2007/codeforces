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
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int ok = 1;
        set<int> q;
        for (int i = 0; i < n; i++) {
            q.insert(b[i]);
            if (i > 0 && b[i] != b[i - 1]) {
                int l = min(b[i - 1], b[i]);
                int r = max(b[i - 1], b[i]);
                if (*q.upper_bound(l) < r) {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}