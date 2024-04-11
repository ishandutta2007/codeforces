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

int u[5][5];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    for(char c : s) {
        if(c == '0') {
            for(int i = 1;i <= 4;i += 2) {
                if(!u[i][1] && !u[i + 1][1]) {
                    u[i][1] = u[i + 1][1] = 1;
                    cout << i << " 1\n";
                    break;
                }
            }
        }else {
            for(int i = 1;i <= 4;i++) {
                if(!u[i][2] && !u[i][3]) {
                    u[i][2] = u[i][3] = 1;
                    cout << i << " 2\n";
                    break;
                }
            }
        }
        vector< vector< int > > del(5, vector< int >(5));
        for(int i = 1;i <= 4;i++) {
            for(int j = 1;j <= 4;j++) {
                int row = 1;
                int col = 1;
                for(int q = 1;q <= 4;q++) {
                    row &= u[i][q];
                    col &= u[q][j];
                }
                if(row || col) {
                    del[i][j] = 1;
                }
            }
        }
        for(int i = 1;i <= 4;i++) {
            for(int j = 1;j <= 4;j++) {
                if(del[i][j]) {
                    u[i][j] = 0;
                }
            }
        }
    }

    return 0;
}