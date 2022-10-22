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

const int N = 2003;

int n, m;
int a[N], b[N];
int cnt[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
         cin >> a[i];
         b[i - 1] = a[i];
    }

    sort(b, b + n);
    m = unique(b, b + n) - b;

    if (n == m) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b, b + m, a[i]) - b;
    }

    int res = inf;

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n; i++) {
            cnt[a[i]] = 0;
        }
        int ok = 1;
        for (int i = 1; i < l; i++) {
            if (cnt[a[i]]) {
                ok = 0;
                break;
            } else {
                cnt[a[i]] = 1;
            }
        }
        if (!ok) continue;
        int r = n;
        while (r > l && !cnt[a[r]]) {
            cnt[a[r--]]++;
        }
        res = min(res, r - l + 1);
    }

    cout << res << "\n";

    return 0;
}