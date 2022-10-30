#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;

template <typename A, typename B>
inline void chmin(A& a, B b) {
    if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
    if (a < b) a = b;
}

template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
    ost << "{" << p.first << "," << p.second << "}";
    return ost;
}

template <class T>
ostream& operator<<(ostream& ost, const vector<T>& v) {
    ost << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) ost << ",";
        ost << v[i];
    }
    ost << "}";
    return ost;
}

inline int topbit(unsigned long long x) {
    return x ? 63 - __builtin_clzll(x) : -1;
}

inline int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x) {
    return __builtin_parity(x);
}

const int INF = 1001001001;

pint NG(-1, -1);
pint check(int x, int y, int L, const vpint& ps) {
    chmax(x, 0ll);
    chmax(y, 0ll);
    for (auto p : ps) {
        if (x + L < p.fi) return NG;
        if (x - L > p.fi) return NG;
        if (y + L < p.se) return NG;
        if (y - L > p.se) return NG;
        if (y - x + L < p.se - p.fi) return NG;
        if (y - x - L > p.se - p.fi) return NG;
    }
    return {x, y};
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<pint> ps;
    int max_x = 0, max_y = 0, max_yx = -INF, max_xy = -INF;
    rep(i, N) {
        string s;
        cin >> s;
        int x = count(all(s), 'B');
        int y = s.size() - x;
        chmax(max_x, x);
        chmax(max_y, y);
        chmax(max_yx, y - x);
        chmax(max_xy, x - y);
        ps.eb(x, y);
    }

    int lb = -1, ub = 1000'000;
    pint ans;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        int x, y, ok = false;
        pint p;
        y = max_y - mid;

        x = max_x - mid;
        p = check(x, y, mid, ps);
        if (p != NG) {
            ub = mid;
            ans = p;
            continue;
        }

        x = max_xy + y - mid;
        p = check(x, y, mid, ps);
        if (p != NG) {
            ub = mid;
            ans = p;
            continue;
        }

        x = y - max_yx + mid;
        p = check(x, y, mid, ps);
        if (p != NG) {
            ub = mid;
            ans = p;
            continue;
        }

        x = max_x - mid;
        y = x + max_yx - mid;
        p = check(x, y, mid, ps);
        if (p != NG) {
            ub = mid;
            ans = p;
            continue;
        }

        lb = mid;
    }
    cout << ub << endl;

    if (ans == pint(0, 0)) {
        if (check(1, 0, ub, ps) != NG)
            ans.fi++;
        else if (check(0, 1, ub, ps) != NG) {
            ans.se++;
        } else {
            ans.fi++;
            ans.se++;
        }
    }

    cout << string(ans.fi, 'B') << string(ans.se, 'N') << endl;
    return 0;
}