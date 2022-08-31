#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 300228;
pair<ll,int> x[MAXN];
int n;

void go(ll a, ll b, bool swp) {
    vector<int> ans[2];
    int l = 0;
    for (int i = 0; i < 2; ++i) {
        ll cn = (i ? b : a);
        int r = l;
        while (r <= n && ((r == l) || (x[r - 1].first * (r - l) < cn))) {
            ++r;
        }

        if (r > n) {
            return;
        }

        for (int j = l; j < r; ++j) {
            ans[i ^ swp].push_back(x[j].second);
        }

        l = r;
    }

    cout << "Yes\n";
    cout << ans[0].size() << " " << ans[1].size() << "\n";
    sort(ans[0].begin(), ans[0].end());
    sort(ans[1].begin(), ans[1].end());

    for (auto& val : ans[0]) {
        cout << val << " ";
    }

    cout << "\n";

    for (auto& val : ans[1]) {
        cout << val << " ";
    }

    cout << "\n";

    exit(0);
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    ll a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first;
        x[i].second = i + 1;
    }

    sort(x, x + n, greater<>{});

    go(a, b, false);
    go(b, a, true);

    cout << "No\n";
}