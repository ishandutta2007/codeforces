#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 300005, INF = 1E9 + 7;

int n, k, val[N];
vector<pair<int, int>> eve[N];

struct segment {
    int x, y, ind;

    segment(int _x = 0, int _y = 0, int _ind = 0) : x(_x), y(_y), ind(_ind) {}

    inline bool operator<(const segment &oth) const {
        return x < oth.x || (x == oth.x && y < oth.y);
    }
} a[N];
set<segment> se;

long long check(int u) {
    long long ans = 0, cur = 0;
    int sum = 0, cnt = 0;
    fill(val + 1, val + n + 1, 0);
    for (int i = 1, pt = 1; i <= n; i++) {
        for (pair<int, int> &v : eve[i]) {
            val[v.fi] += v.se;
            if (v.fi >= pt) {
                sum += v.se;
            } else {
                cur += 1LL * v.fi * v.se;
            }
        }
        for (; sum > u; pt++) {
            sum -= val[pt];
            cur += 1LL * pt * val[pt];
        }
        if ((cnt += pt - 1) > k) {
            return -1;
        }
        ans += cur + 1LL * (pt - 1) * sum;
    }
    return ans + 1LL * (k - cnt) * u;
}

long long find_ans() {
    int le = 0, ri = INF;
    while (le <= ri) {
        int mi = (le + ri) / 2;
        if (check(mi) == -1) {
            le = mi + 1;
        } else {
            ri = mi - 1;
        }
    }
    return check(le);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].ind = i;
    }
    for (int i = 1; i <= n; i++) {
        auto it = se.lower_bound(segment(a[i].x));
        if (it != se.begin() && prev(it)->y > a[i].x) {
            it = prev(it);
            segment cur = *it;
            if (cur.y > a[i].y) {
                eve[i].push_back({cur.ind, a[i].x - a[i].y});
                se.insert(segment(cur.x, a[i].x, cur.ind));
                se.insert(segment(a[i].y, cur.y, cur.ind));
            } else {
                eve[i].push_back({cur.ind, a[i].x - cur.y});
                cur.y = a[i].x; se.insert(cur);
            }
            it = se.erase(it);
        }
        for (; it != se.end() && it->y <= a[i].y; it = se.erase(it)) {
            eve[i].push_back({it->ind, it->x - it->y});
        }
        if (it != se.end() && it->x < a[i].y) {
            segment cur = *it;
            eve[i].push_back({cur.ind, it->x - a[i].y});
            it = se.erase(it);
            cur.x = a[i].y; se.insert(cur);
        }
        eve[i].push_back({i, a[i].y - a[i].x});
        se.insert(a[i]);
    }
    cout << find_ans();
}