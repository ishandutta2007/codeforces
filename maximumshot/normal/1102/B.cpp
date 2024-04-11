#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table; // the usage is the same as the unordered_map

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    vector< int > a(n + 1), c(n + 1), cnt(k + 1);
    vector< gp_hash_table< int, int > > have(k + 1);

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        int j = -1;
        for(int q = 1;q <= k;q++) {
            if(have[q].find(a[i]) != have[q].end()) continue;
            if(j == -1 || cnt[j] > cnt[q]) j = q;
        }
        if(j == -1) {
            cout << "NO\n";
            return 0;
        }
        c[i] = j;
        have[j][ a[i] ] = 1;
        cnt[j]++;
    }

    cout << "YES\n";

    for(int i = 1;i <= n;i++) {
        cout << c[i] << " \n"[i == n];
    }

    return 0;
}