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

    int n, m;

    cin >> n >> m;

    vector< int > a(n + 1);
    int c = n;

    for(int x, i = 0;i < m;i++) {
        cin >> x;
        if(!a[x]++) c--;
        if(!c) {
            cout << "1";
            for(int j = 1;j <= n;j++) {
                if(!--a[j]) c++;
            }
        }else {
            cout << "0";
        }
    }

    cout << "\n";

    return 0;
}