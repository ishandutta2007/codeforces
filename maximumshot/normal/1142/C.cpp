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

struct pt {
    ll x, y;
    bool operator < (const pt &o) const {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
};

bool isUpper(pt a, pt b, pt c) {
    ll x1 = a.x;
    ll y1 = a.y;
    ll x2 = b.x;
    ll y2 = b.y;
    ll x3 = c.x;
    ll y3 = c.y;
    ll le = y3 - x3 * x3 - y1 + x1 * x1 + (x3 - x1) * (x1 + x2);
    ll ri = (x3 - x1) * (y2 - y1);
    return le * (x2 - x1) >= ri;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pt> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p.begin(), p.end());

    {
        vector<pt> p2;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && p[i].x == p[i + 1].x) {
                continue;
            }
            p2.push_back(p[i]);
        }
        p = p2;
        n = (int)p.size();
    }

    vector<pt> st;

//    for (pt pi : p) {
//        cout << pi.x << ", " << pi.y << "\n";
//    }

    for (int i = 0; i < n; i++) {
        while ((int)st.size() >= 2) {
            pt a = st[(int)st.size() - 2];
            pt b = st[(int)st.size() - 1];
            if (isUpper(a, b, p[i])) {
                st.pop_back();
            } else {
                break;
            }
        }
        st.push_back(p[i]);
    }

    cout << (int)st.size() - 1 << "\n";

    return 0;
}