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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<int>> as;
        as.push_back(a);
        for (int it = 0; it < n; it++) {
            vector<int> cnt(n + 1);
            const auto& was = as.back();
            for (int i = 1; i <= n; i++)
                cnt[was[i]]++;
            vector<int> b = was;
            for (int i = 1; i <= n; i++)
                b[i] = cnt[was[i]];
            as.push_back(b);
        }
        int q;
        cin >> q;
        for (int it = 0; it < q; it++) {
            int x, k;
            cin >> x >> k;
            k = min(k, (int) as.size() - 1);
            cout << as[k][x] << "\n";
        }
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