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

int n, k;
string s;
vector< int > p[26];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;

    for(int i = 0;i < n;i++) {
        p[ s[i] - 'a' ].push_back(i);
    }

    int x = 0;

    for(int c = 0;c < 26;c++) {
        auto &ar = p[c];
        int tmp = 0;
        for(int i = 0;i < (int)ar.size();i++) {
            int j = i;
            while(j + 1 < (int)ar.size() && ar[j + 1] == ar[j] + 1) j++;
            tmp += (j - i + 1) / k;
            i = j;
        }
        x = max(x, tmp);
    }

    cout << x << "\n";

    return 0;
}