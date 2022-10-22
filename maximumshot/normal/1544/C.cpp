#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

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
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        for (int i = 1; i < n; i++) b[i] += b[i - 1];
        auto check = [&](int add) -> bool {
            ll k = n + add;
            ll take = k - (k / 4);
            ll sb = b[min(take, (ll) n) - 1];
            ll tmp = min(ll(add), take);
            ll sa = 100ll * tmp;
            take -= tmp;
            if (take > 0)
                sa += a[take - 1];
            return sa >= sb;
        };
        int bl = -1, br = inf, bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (check(bm)) br = bm;
            else bl = bm;
        }
        cout << br << "\n";
    }

    return 0;
}