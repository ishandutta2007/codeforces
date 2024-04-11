/*
    author:  Maksim1744
    created: 22.07.2021 23:30:49
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
#include "/home/maksim/cpplibs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    {
        if (s == t) {
            cout << 0 << '\n';
            return;
        }
        int c1 = count(s.begin(), s.end(), '1');
        int c2 = count(t.begin(), t.end(), '1');
        if (c1 != c2 || k == 0) {
            cout << -1 << '\n';
            return;
        }
        if (c1 < k) {
            cout << -1 << '\n';
            return;
        }
        if (c1 == k) {
            int p1 = find(s.begin(), s.end(), '1') - s.begin();
            int p2 = find(t.begin(), t.end(), '1') - t.begin();
            while (s[0] == '0') s.erase(s.begin());
            while (t[0] == '0') t.erase(t.begin());
            while (s.back() == '0') s.pop_back();
            while (t.back() == '0') t.pop_back();

            if (s == t) {
                cout << 2 << '\n';
                cout << p1 + 1 << ' ' << n << '\n';
                cout << p2 + 1 << ' ' << n << '\n';
                return;
            }

            reverse(t.begin(), t.end());
            if (s == t) {
                cout << 3 << '\n';
                cout << p1 + 1 << ' ' << n << '\n';
                cout << p2 + 1 << ' ' << n << '\n';
                cout << p2 + 1 << ' ' << p2 + t.size() << '\n';
                return;
            }
            cout << -1 << '\n';
            return;
        }
    }

    auto make_intervals = [&](string s) {
        s = "1" + s + "1";
        vector<int> v;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '1')
                v.pb(i);
        vector<int> res;
        for (int i = 0; i + 1 < v.size(); ++i)
            res.pb(v[i + 1] - v[i] - 1);
        return res;
    };

    auto v1 = make_intervals(s);
    auto v2 = make_intervals(t);

    auto process = [&](vector<int> v) {
        vector<pair<int, int>> ans;

        const int inf = 1e9;

        auto sw = [&](int l, int tor) {
            if (tor == inf)
                tor = v[l] - v[l + k];
            show(v, l, tor);
            assert(l + k + 1 <= v.size());
            if (tor >= 0) {
                assert(v[l] >= tor);
                int len = accumulate(v.begin() + l + 1, v.begin() + l + k, 0) + k + tor;
                int fr = accumulate(v.begin(), v.begin() + l + 1, 0) + l - tor;
                show(fr, len);
                ans.eb(fr, fr + len - 1);
                reverse(v.begin() + l + 1, v.begin() + l + k);
                v[l] -= tor;
                v[l + k] += tor;
            } else {
                tor = -tor;
                assert(v[l + k] >= tor);
                int len = accumulate(v.begin() + l + 1, v.begin() + l + k, 0) + k + tor;
                int fr = accumulate(v.begin(), v.begin() + l + 1, 0) + l;
                show(fr, len);
                ans.eb(fr, fr + len - 1);
                reverse(v.begin() + l + 1, v.begin() + l + k);
                v[l] += tor;
                v[l + k] -= tor;
            }
        };
        
        while (v.size() > k + 2) {
            if (v.back() == 0) {
                v.pop_back();
                continue;
            }
            sw(v.size() - k - 1, -v.back());
        }

        assert(v.size() == k + 2);
        while (true) {
            if (k % 2 == 1) {
                if (*max_element(v.begin() + 1, v.end()) == 0) break;
            } else {
                if (*max_element(v.begin() + 1, v.end() - 1) == 0) {
                    sw(1, inf);
                    break;
                }
                if (*max_element(v.begin() + 2, v.end()) == 0) break;
            }

            sw(0, -v[v.size() - 2]);
            sw(1, k % 2 == 1 ? inf : v[1]);
        }

        return mp(v, ans);
    };

    auto [r1, moves1] = process(v1);
    auto [r2, moves2] = process(v2);

    if (r1 != r2) {
        cout << -1 << '\n';
        return;
    }

    reverse(moves2.begin(), moves2.end());
    cout << moves1.size() + moves2.size() << '\n';
    for (auto [l, r] : moves1) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
    for (auto [l, r] : moves2) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
        cout.flush();
    }

    return 0;
}