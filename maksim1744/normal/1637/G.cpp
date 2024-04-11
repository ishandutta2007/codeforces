/*
    author:  Maksim1744
    created: 12.02.2022 19:11:39
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

void test_case(int test) {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }

    vector<pair<int, int>> ops;
    multiset<int> p2;
    multiset<int> cur;
    for (int i = 1; i <= n; ++i) {
        cur.insert(i);
    }
    while (!cur.empty()) {
        multiset<int> other;
        while (!cur.empty()) {
            int v = *--cur.end();
            cur.erase(--cur.end());
            int p = 1;
            while (p < v) p *= 2;
            if (p == v) {
                p2.insert(v);
                continue;
            }
            int k = p - v;
            auto it = cur.find(k);
            assert(it != cur.end());
            cur.erase(it);
            ops.eb(k, v);
            other.insert(abs(k - v));
            p2.insert(k + v);
        }
        swap(cur, other);
    }

    swap(cur, p2);
    int target = *--cur.end();
    cur.erase(target);
    while (!cur.empty()) {
        if (*cur.begin() == 0) {
            auto it = cur.lower_bound(1);
            if (it == cur.end()) {
                ops.eb(0, target);
                cur.erase(cur.begin());
            } else {
                ops.eb(0, *it);
                int sm = *it;
                cur.erase(it);
                cur.erase(cur.begin());
                cur.insert(sm);
                cur.insert(sm);
            }
        } else {
            auto it1 = cur.begin();
            auto it2 = next(it1);
            assert(it2 != cur.end());
            while (*it1 != *it2) {
                ++it1;
                ++it2;
                assert(it2 != cur.end());
            }
            int a = *it1;
            cur.erase(it1);
            cur.erase(it2);
            cur.insert(0);
            ops.eb(a, a);
            cur.insert(a * 2);
        }
        cur.erase(target);
    }
    assert(ops.size() <= n * 20);
    cout << ops.size() << '\n';
    for (auto p : ops)
        cout << p << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}