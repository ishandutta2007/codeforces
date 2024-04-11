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

void solve() {
    int n;

    cin >> n;

    vector< pair< pii, int > > a(n);

    int cur = 0;
    for(pair< pii, int > &p : a) {
        cin >> p.first.first >> p.first.second;
        p.second = cur++;
        swap(p.first.second, p.first.first);
    }

    sort(a.begin(), a.end());

    vector< int > suff(n, inf), res(n);

    for(int i = n - 1;i >= 0;i--) {
        if(i + 1 < n) suff[i] = suff[i + 1];
        suff[i] = min(suff[i], a[i].first.second);
        swap(a[i].first.first, a[i].first.second);
    }

    int ok = 0;

//    for(pair< pii, int > p : a) {
//        cout << p.first.first << " .. " << p.first.second << " id = " << p.second << "\n";
//    }

//    for(int i = 0;i < n;i++) {
//        cout << suff[i] << " ";
//    }

//    cout << "\n";

    for(int i = 0;i + 1 < n;i++) {
        if(a[i].first.second < suff[i + 1]) {
            for(int j = 0;j < n;j++) {
                res[ a[j].second ] = 1 + (j > i);
            }
            ok = 1;
            break;
        }
    }

    if(!ok) {
        cout << "-1\n";
    }else {
        for(int i = 0;i < n;i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    while(tt--) {
        solve();
    }

    return 0;
}