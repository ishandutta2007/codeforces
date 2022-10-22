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

    string s;

    cin >> s;

    int n = (int)s.size();
    int l = 0, r = n - 1;

    while(l < n && s[l] != '[') l++;
    l++;
    while(l < n && s[l] != ':') l++;

    while(r >= 0 && s[r] != ']') r--;
    r--;
    while(r >= 0 && s[r] != ':') r--;

    if(l >= r) {
        cout << "-1\n";
        return 0;
    }

    int res = 4;

    for(int i = l + 1;i < r;i++) {
        res += s[i] == '|';
    }

    cout << res << "\n";

    return 0;
}