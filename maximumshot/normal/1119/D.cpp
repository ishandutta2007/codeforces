#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
ll s[N];
ll sh[N];
ll pr[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    sort(s + 1, s + n + 1);
    n = unique(s + 1, s + n + 1) - (s + 1);

    for (int i = 1; i <= n; i++) {
        sh[i] = i < n ? s[i + 1] - s[i] : 2 * inf64;
    }

    sort(sh + 1, sh + n + 1);

    for (int i = 1; i <= n; i++) {
        pr[i] = pr[i - 1] + sh[i];
    }

    int q;

    cin >> q;

    for (int i = 1; i <= q; i++) {
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        ll len = r - l + 1;
        int j = lower_bound(sh + 1, sh + n + 1, len) - sh;
        cout << pr[j - 1] + (n - j + 1) * len << "\n";
    }


    return 0;
}