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

int n, m, k;
int b[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }

    int res = b[n] - b[1] + 1;

    vector< int > a;

    for(int i = 1;i + 1 <= n;i++) {
        a.push_back(b[i + 1] - b[i] - 1);
    }

    sort(a.rbegin(), a.rend());

    for(int i = 0;i < k - 1;i++) {
        res -= a[i];
    }

    cout << res << "\n";

    return 0;
}