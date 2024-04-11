#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int k;

    cin >> k;

    vec< vec< int > > a(k);

    unordered_map< int, pii > mp;

    for(int i = 0;i < k;i++) {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        int sum = 0;
        for(int j = 0;j < sz;j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        for(int j = 0;j < sz;j++) {
            int tmp = sum - a[i][j];
            if(mp.count(tmp)) {
                cout << "YES\n";
                pii hlp = mp[tmp];
                cout << hlp.first + 1 << " " << hlp.second + 1 << "\n";
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
        for(int j = 0;j < sz;j++) {
            mp[sum - a[i][j]] = make_pair(i, j);
        }
    }

    cout << "NO\n";

    return 0;
}