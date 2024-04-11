/*
    author:  Maksim1744
    created: 17.07.2021 17:47:31
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    --a;
    vector<int> b(n, -1);

    int distinct = set<int>(a.begin(), a.end()).size();
    cout << distinct << '\n';
    if (distinct == n) {
        ++a;
        cout << a << '\n';
        return;
    }

    if (distinct == n - 1) {
        int x = -1;
        set<int> was;
        for (int k : a) {
            if (was.count(k)) x = k;
            was.insert(k);
        }

        vector<int> two;
        set<int> without_gift;
        for (int i = 0; i < n; ++i) {
            without_gift.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != x) {
                b[i] = a[i];
                without_gift.erase(b[i]);
            } else {
                two.pb(i);
            }
        }
        assert(two.size() == 2);
        int u = two[0];
        int v = two[1];

        int tou = *without_gift.begin();
        int tov = *without_gift.rbegin();
        assert(tou == x || tov == x);

        if (tou == u || tov == v)
            swap(tou, tov);
        assert(tou != u && tov != v);

        b[u] = tou;
        b[v] = tov;
        ++b;
        cout << b << '\n';
        return;
    }

    set<int> without_gift;
    for (int i = 0; i < n; ++i) {
        without_gift.insert(i);
    }
    vector<int> left;
    for (int i = 0; i < n; ++i) {
        if (without_gift.count(a[i])) {
            b[i] = a[i];
            without_gift.erase(a[i]);
        } else {
            left.pb(i);
        }
    }
    show(left);
    show(without_gift);

    vector<pair<int, int>> prs;
    set<int> taken;
    for (int k : left) {
        if (without_gift.count(k)) {
            prs.eb(k, k);
            taken.insert(k);
            without_gift.erase(k);
        }
    }
    show(prs);
    show(without_gift);
    for (int k : left) {
        if (!taken.count(k)) {
            prs.eb(k, *without_gift.begin());
            without_gift.erase(without_gift.begin());
        }
    }
    show(prs);

    for (int i = 0; i < prs.size(); ++i) {
        b[prs[i].first] = prs[(i + 1) % prs.size()].second;
    }
    ++b;
    cout << b << '\n';
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