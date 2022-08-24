#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;


multiset<ll> a;
ll mdf = 0;

const int MAXN = 100002;

ll v[MAXN];

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i) {
        a.insert(v[i] + mdf);

        ll t;
        cin >> t;

        ll cur = 0;
        while (!a.empty()) {
            ll d = *a.begin() - mdf;
            if (d <= t) {
                cur += d;
                a.erase(a.begin());
            } else {
                break;
            }
        }

        mdf += t;
        cout << cur + t * ll(a.size()) << " ";
    }
}