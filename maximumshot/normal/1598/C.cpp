#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll S = 0;
        for (int i = 0; i < n; i++)
            S += a[i];
        sort(a.begin(), a.end());
        ll res = 0;
        for (int i = 0, j = n - 1, k = n - 1; i < n; i++) {
            while (j >= 0 && 1ll * n * (a[i] + a[j]) > 2 * S) j--;
            while (k >= 0 && 1ll * n * (a[i] + a[k]) >= 2 * S) k--;
            // [k, j)
            res += max(0, j - max(i, k));
        }
        cout << res << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}