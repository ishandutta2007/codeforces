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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pll> a(n);
    vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i].first == a[j].first) {
                cnt[i]++;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        int ok = 0;
        for (int j = 0; j < n; j++) {
            if ((a[j].first & a[i].first) == a[i].first) {
                if (cnt[j] > 1) {
                    ok = 1;
                }
            }
        }
        if (ok) {
            res += a[i].second;
        }
    }

    cout << res << "\n";

    return 0;
}