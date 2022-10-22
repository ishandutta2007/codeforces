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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> mx(n + 1, -inf), last(n + 1, -1);
        for (int i = 0; i < n; i++) {
            int len = i - last[a[i]];
            last[a[i]] = i;
            mx[a[i]] = max(mx[a[i]], len);
        }
        for (int i = 0; i < n; i++) {
            mx[a[i]] = max(mx[a[i]], n - last[a[i]]);
        }
        vector<int> res(n + 1, inf);
        for (int x = 1; x <= n; x++) {
            if (mx[x] == -inf)
                continue;
            res[mx[x]] = min(res[mx[x]], x);
        }
        for (int i = 1; i <= n; i++)
            res[i] = min(res[i], res[i - 1]);
        for (int k = 1; k <= n; k++) {
            if (res[k] == inf)
                res[k] = -1;
            cout << res[k] << " ";
        }
        cout << "\n";
    }

    return 0;
}