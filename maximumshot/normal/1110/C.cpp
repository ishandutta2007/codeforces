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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;

    cin >> q;

    for(int iter = 0;iter < q;iter++) {
        int a;
        cin >> a;
        if (a & (a + 1)) {
            int j = 24;
            while(!((1 << j) & a)) j--;
//            cout << "J = " << j << "\n";
            cout << (1 << (j + 1)) - 1 << "\n";
        } else{
            int p = 2;
            while(a % p && p * p <= a) p++;
            if (a % p == 0)
                cout << a / p << "\n";
            else
                cout << 1 << "\n";
        }
    }

    return 0;
}