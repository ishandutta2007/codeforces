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

const int N = 2e5 + 5;

int n, m, ta, tb, k;
int a[N], b[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> ta >> tb >> k;

    if (n <= k || m <= k) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int res = -1;

    for (int i = 0; i <= k; i++) {
        int x = a[i] + ta;
        if (x > b[m - 1]) {
            cout << "-1\n";
            return 0;
        }
        int j = lower_bound(b, b + m, x) - b;
        j += k - i;
        if (j >= m) {
            cout << "-1\n";
            return 0;
        }
        res = max(res, b[j] + tb);
    }

    cout << res << "\n";

    return 0;
}