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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s;

    cin >> s;

    int n = (int)s.size();

    for(int i = 0;i + 1 < n;i++) {
        string t = s.substr(i + 1) + s.substr(0, i + 1);
        string t2 = t;
        reverse(t2.begin(), t2.end());
        if(s != t && t2 == t) {
            cout << "1\n";
            return 0;
        }
    }

    for(int i = 0;i < n / 2;i++) {
        if(s[i] != s[0]) {
            cout << "2\n";
            return 0;
        }
    }

    cout << "Impossible\n";

    return 0;
}