#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long  ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

template <class T>
struct ConvexHullTrick {
    size_t sz;
    vec< pair< T, T > > Lines, st;

    ConvexHullTrick() {
        sz = 0;
    }

    // a < b
    /*bool check(pair< T, T > a, pair< T, T > b) const {
        if(a.second < T(0)) a.first = -a.first, a.second = -a.second;
        if(b.second < T(0)) b.first = -b.first, b.second = -b.second;
        return 1ll * a.first * b.second < 1ll * b.first * a.second;
    }*/

    bool check(pair< T, T > a, pair< T, T > b) const {
        return 1.0 * a.first / a.second < 1.0 * b.first / b.second;
    }

    void add_line(pair< T, T > L) {
        pair< T, T > l1, l2;
        while((int)st.size() > 1) {
            l1 = st[(int)st.size() - 2];
            l2 = st[(int)st.size() - 1];
            if(check({l1.second - l2.second, l2.first - l1.first}, {l2.second - L.second, L.first - l2.first})) break;
            st.pop_back();
        }
        st.push_back(L);
        sz = st.size();
    }

    ConvexHullTrick(vec< pair< T, T > > _lines) : Lines(_lines) {
        sort(ALL(Lines));
        for(size_t i = 0;i < Lines.size();i++) add_line(Lines[i]);
    }

    bool check(size_t i, T x) const {
        pair< T, T > l1, l2;
        l1 = st[i - 1];
        l2 = st[i];
        // a <= b
        // !(a > b)
        // !(b < a)
        return !check({x, T(1)}, {l1.second - l2.second, l2.first - l1.first});
    }

    T get(T x) const {
        if(sz == 1 || !check(1, x)) return st[0].first * x + st[0].second;
        size_t bl, br, bm;
        bl = 1;
        br = sz - 1;
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(check(bm, x)) bl = bm;
            else br = bm - 1;
        }
        return min(st[bl].first * x + st[bl].second, st[br].first * x + st[br].second);
    }

    void show() {
        cout << "sz = " << sz << " : \n";
        for(int i = 0;i < sz;i++) {
            cout << st[i].first << ' ' << st[i].second << "\n";
        }
        for(int i = 1;i < sz;i++) {
            pair< double, double > l1, l2;
            l1 = st[i - 1];
            l2 = st[i];
            cout << fixed << setprecision(3) << (l1.second - l2.second) / (l2.first - l1.first) << " ";
        }
        cout << "\n\n";
    }
};

bool solve() {

    int n;
    scanf("%d", &n);

    vec< int > a(n), b(n);

    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
    for(int i = 0;i < n;i++) scanf("%d", &b[i]);

    vec< ll > dp(n, LLONG_MAX);
    ConvexHullTrick< ll > hull;

    dp[0] = 0;
    hull.add_line({b[0], 0});

    for(int i = 1;i < n;i++) {
        dp[i] = hull.get(a[i]);
        hull.add_line({b[i], dp[i]});
    }

    printf("%I64d\n", dp[n - 1]);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}