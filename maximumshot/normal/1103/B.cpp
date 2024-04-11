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

char f(int x, int y) {
    cout << "? " << x << " " << y << endl;
    char c;
    cin >> c;
    return c;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        string s;
        cin >> s;
        if(s == "end") break;
        if(f(0, 1) == 'x') {
            cout << "! 1" << endl;
            continue;
        }
        int bl = 1, tmp;
        while(f(bl << 1, bl) == 'x') bl <<= 1;
        tmp = bl;
        int br = bl << 1;
        int bm;
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(f(bm, tmp) == 'y') {
                br = bm;
            }else {
                bl = bm;
            }
        }
        cout << "! " << br << endl;
    }

    return 0;
}