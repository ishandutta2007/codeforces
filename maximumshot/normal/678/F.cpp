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
    bool check(pair< T, T > a, pair< T, T > b) const {
        if(a.second < 0) a.first = -a.first, a.second = -a.second;
        if(b.second < 0) b.first = -b.first, b.second = -b.second;
        return 1ll * a.first * b.second < 1ll * b.first * a.second;
    }

    void add_line(pair< T, T > L) {
        pair< T, T > l1, l2;
        while(!st.empty() && st.back().first == L.first) st.pop_back();
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
        return !check({x, 1}, {l1.second - l2.second, l2.first - l1.first});
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
        return max(st[bl].first * x + st[bl].second, st[br].first * x + st[br].second);
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

ll const MIN_VALUE = -inf64 - inf - 1;

int n;
vec< char > del;
vec< pii > Lines;
vec< int > type, que;
vec< vec< pair< ll, ll > > > t_lines;
vec< ConvexHullTrick< ll > > t_hull;

void add(int v, int tl, int tr, int l, int r, pair< ll, ll > line) {
    if(l <= tl && tr <= r) {
        t_lines[v].push_back(line);
    }else {
        int tm = (tl + tr) >> 1;
        if(l <= tm) add(v * 2 + 1, tl, tm, l, r, line);
        if(r > tm) add(v * 2 + 2, tm + 1, tr, l, r, line);
    }
}

ll get(int v, int tl, int tr, int pos, ll x) {
    ll res = MIN_VALUE;
    if(t_hull[v].sz > 0) res = max(res, t_hull[v].get(x));
    if(tl < tr) {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) res = max(res, get(v * 2 + 1, tl, tm, pos, x));
        else res = max(res, get(v * 2 + 2, tm + 1, tr, pos, x));
    }
    return res;
}

bool solve() {

    scanf("%d", &n);

    del.resize(n);
    Lines.resize(n);
    que.resize(n);
    type.resize(n);
    t_lines.resize(4 * n);
    t_hull.resize(4 * n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &type[i]);
        if(type[i] == 1) {
            scanf("%d %d", &Lines[i].first, &Lines[i].second);
        }else if(type[i] == 2) {
            scanf("%d", &x);
            x--;
            // [x .. i]
            del[x] = 1;
            add(0, 0, n - 1, x, i, Lines[x]);
        }else { // type[i] == 3
            scanf("%d", &que[i]);
        }
    }

    for(int i = 0;i < n;i++) {
        if(type[i] == 1 && !del[i]) {
            add(0, 0, n - 1, i, n - 1, Lines[i]);
        }
    }

    for(int i = 0;i < 4 * n;i++) {
        if(t_lines[i].empty()) continue;
        t_hull[i] = ConvexHullTrick< ll >(t_lines[i]);
    }

    for(int i = 0;i < n;i++) {
        if(type[i] == 3) {
            ll x = get(0, 0, n - 1, i, que[i]);
            if(x == MIN_VALUE) printf("EMPTY SET\n");
            else printf("%I64d\n", x);
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}