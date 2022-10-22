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

void solve() {
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<pii> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i].second;
    for (int i = 0; i < n; i++)
        cin >> tasks[i].first;
    sort(tasks.begin(), tasks.end());
    ll cost = 0;
    int res = 0;
    vector<int> ca(n + 1), cb(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        ca[i] = ca[i + 1], cb[i] = cb[i + 1];
        if (tasks[i].second)
            cb[i]++;
        else
            ca[i]++;
    }
    for (int i = -1; i < n; i++) {
        if (i >= 0)
            cost += a + tasks[i].second * (b - a);
        if (i == -1 || i + 1 == n || tasks[i].first < tasks[i + 1].first) {
            int fn = i + 1 < n ? tasks[i + 1].first - 1 : T;
            if (cost <= fn) {
                int cn = i + 1;
                int ost = fn - cost;
                int cca = ca[i + 1], ccb = cb[i + 1];
                int tmp;

                tmp = min(cca, ost / a);
                cn += tmp;
                ost -= tmp * a;
                tmp = min(ccb, ost / b);
                cn += tmp;
                ost -= tmp * b;

                res = max(res, cn);
            }
        }
    }
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}