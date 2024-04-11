#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> x(k), used(n + 1), mn(n + 1, inf), mx(n + 1, -inf);

    for (int i = 0; i < k; i++) {
        cin >> x[i];
        used[x[i]] = 1;
        mx[x[i]] = max(mx[x[i]], i + 1);
        mn[x[i]] = min(mn[x[i]], i + 1);
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            res++;
            if (i > 1) res++;
            if (i < n) res++;
            continue;
        }
        if (i + 1 <= n) {
            if (!used[i + 1] || mx[i + 1] <= mn[i]) {
                res++;
            }
        }
        if (i > 1) {
            if (!used[i - 1] || mx[i - 1] <= mn[i]) {
                res++;
            }
        }
    }

    cout << res << "\n";

    return 0;
}