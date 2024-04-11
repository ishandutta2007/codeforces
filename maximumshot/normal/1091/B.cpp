#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    map< pii, int > cnt;

    int n;

    cin >> n;

    vector< pii > a(n);

    for(pii & p : a) {
        cin >> p.first >> p.second;
    }

    vector< pii > b(n);

    for(pii & p : b) {
        cin >> p.first >> p.second;
    }

    for(pii p : a) {
        for(pii q : b) {
            pii t = {p.first + q.first, p.second + q.second};
            cnt[t]++;
        }
    }

    pii res = {-1, -1};
    int mx = -1;

    for(pair< pii, int > iter : cnt) {
        if(iter.second > mx) {
            mx = iter.second;
            res = iter.first;
        }
    }

    cout << res.first << " " << res.second << "\n";

    return 0;
}