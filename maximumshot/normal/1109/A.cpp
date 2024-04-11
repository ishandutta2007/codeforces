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

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

ll f(const vector< int > a, int n) {
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j += 2) {
            int x = 0;
            int y = 0;
            int m = (i + j) / 2;
            for(int q = i;q <= m;q++) {
                x ^= a[q];
            }
            for(int q = m + 1;q <= j;q++) {
                y ^= a[q];
            }
            res += x == y;
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    vector< int > a(n + 1);
    vector< int > b[2];

    b[0].push_back(0);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        b[i & 1].push_back(a[i]);
    }

    ll res = 0;

    for(int i = 0;i < 2;i++) {
        auto &ar = b[i];
        sort(ar.begin(), ar.end());
        for(int j = 0;j < (int)ar.size();j++) {
            int k = j;
            while(k < (int)ar.size() && ar[j] == ar[k]) k++;
            int cnt = k - j;
            res += 1ll * cnt * (cnt - 1) / 2;
            j = k - 1;
        }
    }

    cout << res << "\n";

    return 0;
}