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
        ll W;
        cin >> n >> W;

        vector<pii> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i].first;
            w[i].second = i;
        }

        sort(w.begin(), w.end());

        int ok = 0;
        for (pii item : w) {
            if (2 * item.first >= W && item.first <= W) {
                cout << 1 << "\n" << item.second + 1 << "\n";
                ok = 1;
                break;
            }
        }

        if (ok)
            continue;

        ll cur = 0;
        vector<int> ids;
        for (pii item : w) {
            if (cur + item.first <= W) {
                cur += item.first;
                ids.push_back(item.second);
            } else {
                break;
            }
        }

        if (2 * cur >= W && cur <= W) {
            cout << (int) ids.size() << "\n";
            for (int i : ids)
                cout << i + 1 << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}