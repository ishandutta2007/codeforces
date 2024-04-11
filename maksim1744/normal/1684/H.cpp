/*
    author:  Maksim1744
    created: 19.05.2022 19:20:58
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
    string s;
    cin >> s;
    int n = s.size();
    if (count(s.begin(), s.end(), '1') == 0) {
        cout << -1 << '\n';
        return;
    }

    auto get_lr = [&](const string& s) {
        vector<pair<int, int>> lr(n + 1, {0, 0});
        int last0 = -1;
        int cur1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cur1;
                lr[i + 1] = lr[last0 + 1];
                lr[i + 1].first += cur1;
                lr[i + 1].second += cur1 + cur1 / 2;
            } else {
                if (cur1) {
                    lr[i + 1] = lr[last0 + 1];
                    lr[i + 1].first += cur1;
                    lr[i + 1].second += cur1 + (cur1 + 1) / 2;
                    cur1 = 0;
                } else {
                    lr[i + 1] = lr[i];
                }
                last0 = i;
            }
        }
        return lr;
    };

    auto get_lr2 = [&](const string& s) {
        vector<pair<int, int>> lr(n + 1, {0, 0});
        int last0 = n;
        int cur1 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                ++cur1;
                lr[i] = lr[last0];
                lr[i].first += cur1;
                lr[i].second += cur1 + (cur1 + (last0 != n)) / 2;
            } else {
                lr[i] = lr[i + 1];
                cur1 = 0;
                last0 = i;
            }
        }
        return lr;
    };

    auto L = get_lr(s);
    auto R = get_lr2(s);
    show(L);
    show(R);
    for (int l = 0; l < n; ++l) {
        int val = 0;
        for (int r = l; r < n && r < l + 27; ++r) {
            val = val * 2 + (s[r] - '0');
            pair<int, int> cur = L[l] + R[r + 1];
            cur.first += val;
            cur.second += val;
            int X = (1 << __lg(cur.second));
            if (l == 7 && r == 9) {
                show(cur);
                show(X);
                show(val);
            }
            if (X < cur.first) continue;
            vector<bool> u(n, true);
            for (int i = l; i <= r; ++i)
                u[i] = false;
            vector<int> upgr;
            int ind = n - 2;
            while (ind > r) {
                if (s[ind] == '0') {
                    --ind;
                    continue;
                }
                upgr.pb(ind);
                ind -= 2;
            }
            ind = l - 2;
            while (ind >= 0) {
                if (s[ind] == '0') {
                    --ind;
                    continue;
                }
                upgr.pb(ind);
                ind -= 2;
            }
            show(cur);
            show(s, l, r);
            show(upgr.size());
            assert(upgr.size() == cur.second - cur.first);
            vector<pair<int, int>> ans;
            ans.eb(l, r);
            for (int i = 0; i < X - cur.first; ++i) {
                ans.eb(upgr[i], upgr[i] + 1);
                u[upgr[i]] = u[upgr[i] + 1] = false;
            }
            for (int i = 0; i < n; ++i) {
                if (u[i])
                    ans.eb(i, i);
            }
            ++ans;
            cout << ans.size() << '\n';
            for (auto p : ans)
                cout << p << '\n';
            return;
        }
    }
    assert(false);
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