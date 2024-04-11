#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector< int > pr(n), sf(n);

    for(int i = 0;i < n;i++) {
        if(i) pr[i] = pr[i - 1];
        if(s[i] == '(') pr[i]++;
        else pr[i]--;
    }

    for(int i = n - 1;i >= 0;i--) {
        if(i + 1 < n) sf[i] = sf[i + 1];
        if(s[i] == ')') sf[i]++;
        else sf[i]--;
    }

    vector< int > mn_pr(n), mn_sf(n);

    for(int i = 0;i < n;i++) {
        if(i) mn_pr[i] = mn_pr[i - 1];
        mn_pr[i] = min(mn_pr[i], pr[i]);
    }

    for(int i = n - 1;i >= 0;i--) {
        if(i + 1 < n) mn_sf[i] = mn_sf[i + 1];
        mn_sf[i] = min(mn_sf[i], sf[i]);
    }

    int res = 0;

    for(int i = 0;i < n;i++) {

        if(i > 0 && mn_pr[i - 1] < 0) continue;
        if(i + 1 < n && mn_sf[i + 1] < 0) continue;
        int b = i ? pr[i - 1] : 0;
        if(s[i] == '(') {
            if(!b) continue;
            b--;
            res += b == (i + 1 == n ? 0 : sf[i + 1]);
        }else {
            b++;
            res += b == (i + 1 == n ? 0 : sf[i + 1]);
        }
    }

    cout << res << "\n";

    return 0;
}