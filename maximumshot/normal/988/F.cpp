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

    int a, n, m;

    cin >> a >> n >> m;

    vec< pii > seg(n);
    for(int i = 0;i < n;i++) cin >> seg[i].first >> seg[i].second;
    vec< pii > pts(m);
    for(int i = 0;i < m;i++) cin >> pts[i].first >> pts[i].second;

    set< int > rs;
    for(pii p : seg) rs.insert(p.second);

    sort(ALL(seg));
    sort(ALL(pts));

    if(pts[0].first > seg[0].first) {
        cout << "-1\n";
        return 0;
    }

    vec< int > dp(m, inf);

    for(int i = 0;i < m;i++) {
        if(pts[i].first <= seg[0].first) {
            dp[i] = 0;
            continue;
        }
        bool in_seg = false;
        int it = lower_bound(ALL(seg), make_pair(pts[i].first, -inf)) - seg.begin() - 1;
        if(it >= 0 && it < (int)seg.size() && pts[i].first <= seg[it].second) {
            in_seg = true;
        }
        for(int j = i - 1;j >= 0;j--) {
            if(in_seg) {
                dp[i] = min(dp[i], dp[j] + (pts[i].first - pts[j].first) * pts[j].second);
                continue;
            }
            auto fnd = rs.upper_bound(pts[i].first);
            int tmp = 0;
            if(fnd == rs.begin()) { }
            else {
                fnd--;
                tmp += max(0, *fnd - pts[j].first) * pts[j].second;
            }
            dp[i] = min(dp[i], dp[j] + tmp);
        }
    }

    int res = inf;
    int mxr = *(--rs.end());

    for(int i = 0;i < m;i++) {
        if(dp[i] == inf) continue;
        int tmp = dp[i] + max(0, mxr - pts[i].first) * pts[i].second;
        res = min(res, tmp);
    }

    cout << res << "\n";

    return 0;
}