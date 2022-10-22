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
        vector<int> a(n + 2), b;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        b = a;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                b[i] = max(a[i - 1], a[i + 1]);
        }
        for (int i = 1; i <= n; i++) {
            res += abs(a[i] - b[i]);
            if (i < n)
                res += abs(b[i] - b[i + 1]);
        }
        res += b[1] + b[n];
        cout << res << "\n";
    }

    return 0;
}