/*
    author:  Maksim1744
    created: 24.05.2021 12:47:34
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

string make_log(vector<int> a) {
    string res;
    int n = a.size();
    vector<int> b(n);
    y_combinator([&](auto merge_sort, int l, int r) -> void {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        merge_sort(l, m);
        merge_sort(m, r);
        int i = l, j = m, k = l;
        while (i < m && j < r) {
            if (a[i] < a[j]) {
                res.pb('0');
                b[k] = a[i];
                ++i;
            } else {
                res.pb('1');
                b[k] = a[j];
                ++j;
            }
            ++k;
        }
        while (i < m) {
            b[k] = a[i];
            ++i;
            ++k;
        }
        while (j < r) {
            b[k] = a[j];
            ++j;
            ++k;
        }
        for (int p = l; p < r; ++p)
            a[p] = b[p];
    })(0, n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    for (int n = 1;; ++n) {
        int it = 0;
        bool ok = true;
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        vector<int> b(n);
        y_combinator([&](auto merge_sort, int l, int r) -> void {
            if (r - l <= 1) return;
            int m = (l + r) / 2;
            merge_sort(l, m);
            merge_sort(m, r);
            int i = l, j = m, k = l;
            if (!ok) return;
            while (i < m && j < r) {
                if (it == s.size()) {
                    ok = false;
                    return;
                }
                if (s[it] == '0') {
                    b[k] = a[i];
                    ++i;
                    ++it;
                } else {
                    ++it;
                    b[k] = a[j];
                    ++j;
                }
                ++k;
            }
            while (i < m) {
                b[k] = a[i];
                ++i;
                ++k;
            }
            while (j < r) {
                b[k] = a[j];
                ++j;
                ++k;
            }
            for (int p = l; p < r; ++p)
                a[p] = b[p];
        })(0, n);
        if (!ok) continue;
        if (it != s.size()) continue;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[a[i]] = i;
        }
        assert(make_log(p) == s);
        ++p;
        cout << p.size() << '\n';
        cout << p << '\n';
        break;
    }

    return 0;
}