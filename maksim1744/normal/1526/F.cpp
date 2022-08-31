/*
    author:  Maksim1744
    created: 28.05.2021 19:09:05
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

#ifdef HOUSE
mt19937_64 rng(1283792);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

void test_case(int test) {
    int n;
    cin >> n;
    int q = 0;
    auto ask = [&](int a, int b, int c) {
        ++q;
        cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int k;
        cin >> k;
        if (k == -1) exit(0);
        return k;
    };

    int l = -1, r = -1;
    int its = 0;
    while (true) {
        assert(its < 100);
        vector<int> v;
        while (v.size() < 4) {
            v.pb(rnd(n));
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }

        vector<pair<int, int>> best;
        for (int i = 0; i < 4; ++i) {
            vector<int> u;
            for (int j = 0; j < 4; ++j) {
                if (i != j)
                    u.pb(v[j]);
            }
            int a = u[0], b = u[1], c = u[2];
            best.eb(ask(a, b, c), i);
        }
        sort(best.begin(), best.end());
        set<int> s;
        for (auto p : best)
            s.insert(p.first);
        if (s.size() != 4) continue;
        if (*prev(s.end()) >= 4) {
            vector<int> u;
            for (int i = 0; i < 4; ++i) {
                if (i != best[2].second && i != best[3].second)
                    u.pb(i);
            }
            assert(u.size() == 2);
            l = v[u[0]];
            r = v[u[1]];
            break;
        }
    }

    show(l, r);

    vector<int> resp(n, 1e9);
    for (int i = 0; i < n; ++i) {
        if (i == l || i == r) continue;
        resp[i] = ask(i, l, r);
    }
    show(resp);
    int mn = mine(resp);
    int dist = mn * 2;
    if (count(resp.begin(), resp.end(), mn) == 2) --dist;
    map<int, int> pos;
    pos[l] = 0;
    pos[r] = dist;
    int mid;
    if (count(resp.begin(), resp.end(), mn) == 2) {
        int a = -1, b = -1;
        for (int i = 0; i < n; ++i) {
            if (resp[i] == mn) {
                if (a == -1) a = i;
                else b = i;
            }
        }
        int na = -1, nb = -1;
        for (int i = 0; i < n; ++i) {
            if (resp[i] == mn + 1) {
                if (na == -1) na = i;
                else nb = i;
            }
        }
        // int r1 = max(ask(l, a, na), ask(l, a, nb));
        int r2 = max(ask(l, b, na), ask(l, b, nb));
        show(a, b);
        show(na, nb);
        show(r2);
        if (r2 == dist / 2)
            swap(a, b);
        pos[a] = dist / 2;
        pos[b] = pos[a] + 1;
        mid = a;
    } else {
        pos[mini(resp)] = dist / 2;
        mid = mini(resp);
    }

    show(mid);
    show(dist);
    show(pos);
    show(l, r);

    for (int i = 0; i < n; ++i) {
        if (resp[i] < dist && !pos.count(i)) {
            int d = ask(l, mid, i);
            show(i, d);
            if (d < dist / 2) {
                pos[i] = dist - resp[i];
            } else {
                pos[i] = resp[i];
            }
        }
    }
    show(pos);
    int nl = -1;
    for (auto [a, b] : pos)
        if (b == 1)
            nl = a;
    show(nl);
    assert(nl != -1);
    for (int i = 0; i < n; ++i) {
        if (resp[i] == dist && !pos.count(i)) {
            int d = ask(l, nl, i);
            show(i, d);
            if (d == dist) continue;
            if (d < dist) {
                pos[i] = -d;
            } else {
                pos[i] = 1 + d;
            }
        }
    }
    show(pos);
    int nr = -1;
    for (auto [a, b] : pos)
        if (b == dist - 1)
            nr = a;
    show(nr);
    assert(nr != -1);
    for (int i = 0; i < n; ++i) {
        if (resp[i] == dist && !pos.count(i)) {
            int d = ask(r, nr, i);
            if (d == dist) continue;
            if (d < dist) {
                pos[i] = dist + d;
            } else {
                pos[i] = dist - 1 - d;
            }
        }
    }
    show(pos);

    for (int i = 0; i < n; ++i) {
        if (resp[i] > dist && !pos.count(i)) {
            int d = ask(l, nl, i);
            if (d == resp[i]) {
                pos[i] = -d;
            } else {
                pos[i] = 1 + d;
            }
        }
    }
    show(pos);
    int fr = 1e9;
    for (auto [a, b] : pos)
        fr = min(fr, b);
    vector<int> p(n, -1);
    for (auto [a, b] : pos)
        p[a] = b - fr;
    if (p[0] > p[1]) {
        for (int i = 0; i < n; ++i) {
            p[i] = n - 1 - p[i];
        }
    }
    ++p;
    cout << "! " << p << endl;
    show(p);
    cerr << q << endl;
    cin >> n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}