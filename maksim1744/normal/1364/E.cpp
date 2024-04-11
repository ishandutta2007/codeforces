/*
    author:  Maksim1744
    created: 13.06.2020 19:21:32
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    if (n <= 100) {
        map<pair<int, int>, int> was;
        auto ask = [&](int i, int j) {
            assert(i != j);
            pair<int, int> p = {i, j};
            if (was.count(p))
                return was[p];
            cout << "? " << i + 1 << ' ' << j + 1 << endl;
            int k;
            cin >> k;
            was[p] = k;
            swap(p.first, p.second);
            was[p] = k;
            return k;
        };
        vector<int> det(11, -1);
        int done = 0;
        while (done < det.size()) {
            int i = 0, j = 0;
            while (i == j) {
                i = rnd(n);
                j = rnd(n);
            }
            int res = ask(i, j);
            for (int k = 0; k < det.size(); ++k) {
                if (det[k] != -1) continue;
                if (((res >> k) & 1) == 0) {
                    det[k] = i;
                    ++done;
                }
            }
        }
        int zero = -1;
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < det.size(); ++j) {
                if (i == det[j]) continue;
                int res = ask(i, det[j]);
                if ((res >> j) & 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                zero = i;
                break;
            }
        }
        assert(zero != -1);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (i == zero) {
                ans[i] = 0;
            } else {
                ans[i] = ask(i, zero);
            }
        }
        cout << "! " << ans << endl;
        return 0;
    }
    map<pair<int, int>, int> was;
    auto ask = [&](int i, int j) {
        assert(i != j);
        pair<int, int> p = {i, j};
        if (was.count(p))
            return was[p];
        cout << "? " << i + 1 << ' ' << j + 1 << endl;
        int k;
        cin >> k;
        was[p] = k;
        swap(p.first, p.second);
        was[p] = k;
        return k;
    };
    int qs = 0;
    vector<int> det(4, -1);
    vector<int> det2(4, -1);
    int done = 0;
    while (done < det.size()) {
        int i = 0, j = 0;
        while (i == j) {
            i = rnd(n);
            j = rnd(n);
        }
        int res = ask(i, j);
        ++qs;
        for (int k = 0; k < det.size(); ++k) {
            if (det[k] != -1) continue;
            if (((res >> (k * 3)) & 7) == 0) {
                det[k] = i;
                det2[k] = j;
                ++done;
            }
        }
    }
    // cerr << "qs = " << qs << endl;
    // cerr << "det = " << det << endl;
    // if (qs + 2048 * 2 > 4269) {
        // cerr << qs << endl;
    //     cout << "? 1 1" << endl;
    //     exit(0);
    // }
    int zero = -1;
    vector<int> after(det.size());
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        swap(p[i], p[rnd(i, n - 1)]);
    }
    int mx = 0;
    while (mx < det.size() && det[mx] == det[0]) ++mx;
    for (int ii = 0; ii < n; ++ii) {
        int i = p[ii];
        bool ok = true;
        for (int j = 0; j < det.size(); ++j) {
            if (i == det[j]) continue;
            int res;
            if (was.count({i, det[j]})) res = was[{i, det[j]}];
            else if (was.count({i, det2[j]})) res = was[{i, det2[j]}];
            else res = ask(i, det[j]);
            ++qs;
            if ((res >> (j * 3)) & 7) {
                after[j]++;
                ok = false;
                if (j > mx) {
                    for (int u = 0; u < j; ++u)
                        det[u] = i;
                    mx = j;
                }
                break;
            }
        }
        if (ok) {
            zero = i;
            break;
        }
    }
    // cerr << "after = " << after << endl;
    // cerr << "asked" << ' ' << qs << endl;
    assert(zero != -1);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (i == zero) {
            ans[i] = 0;
        } else {
            ans[i] = ask(i, zero);
        }
    }
    cout << "! " << ans << endl;

    return 0;
}