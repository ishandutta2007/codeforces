/*
    author:  Maksim1744
    created: 20.06.2021 13:28:00
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, _m;
    cin >> n >> _m;
    vector<int> k(n);
    vector<pair<int, int>> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i] >> left[i] >> right[i];
    }

    set<pair<int, int>> ifleft, ifright;
    ifleft.emplace(0, -1);
    ifright.emplace(0, -1);
    int last = 0;

    vector<vector<pair<int, int>>> del_mem_left(n), del_mem_right(n), ins_mem_left(n), ins_mem_right(n);
    int iter = 0;

    auto ins = [&](int where, pair<int, int> p) {
        if (where == 0) {
            ifleft.insert(p);
            ins_mem_left[iter].pb(p);
        } else {
            ifright.insert(p);
            ins_mem_right[iter].pb(p);
        }
    };
    auto dl = [&](int where, pair<int, int> p) {
        if (where == 0) {
            ifleft.erase(p);
            del_mem_left[iter].pb(p);
        } else {
            ifright.erase(p);
            del_mem_right[iter].pb(p);
        }
    };


    for (int i = 0; i < n; ++i) {
        iter = i;
        auto ifleft_empty = ifleft.empty();
        auto ifright_empty = ifright.empty();
        if (left[i].first <= k[i] && k[i] <= left[i].second) {
            if (right[i].first <= last && last <= right[i].second && !ifright_empty) {
                if (i)
                    ins(0, {last, i - 1});
            }
            while (!ifleft.empty() && ifleft.begin()->first < right[i].first)
                dl(0, *ifleft.begin());
            while (!ifleft.empty() && ifleft.rbegin()->first > right[i].second)
                dl(0, *--ifleft.end());
        } else {
            while (!ifleft.empty())
                dl(0, *ifleft.begin());
        }

        if (right[i].first <= k[i] && k[i] <= right[i].second) {
            if (left[i].first <= last && last <= left[i].second && !ifleft_empty) {
                if (i)
                    ins(1, {last, i - 1});
            }
            while (!ifright.empty() && ifright.begin()->first < left[i].first)
                dl(1, *ifright.begin());
            while (!ifright.empty() && ifright.rbegin()->first > left[i].second)
                dl(1, *--ifright.end());
        } else {
            while (!ifright.empty())
                dl(1, *ifright.begin());
        }


        if (ifleft.empty() && ifright.empty()) {
            cout << "No\n";
            return 0;
        }

        last = k[i];

        show(ifleft, ifright);
    }

    auto undo = [&](int ind) {
        for (auto p : del_mem_left[ind])
            ifleft.insert(p);
        for (auto p : ins_mem_left[ind])
            ifleft.erase(p);
        for (auto p : del_mem_right[ind])
            ifright.insert(p);
        for (auto p : ins_mem_right[ind])
            ifright.erase(p);
    };

    cout << "Yes\n";
    vector<int> ans(n, -1);
    int cur = 0;
    if (ifleft.empty())
        cur = 1;
    int ind = n - 1;
    while (ind >= 0) {
        if (cur == 0) {
            assert(!ifleft.empty());
            int i2 = ifleft.begin()->second;
            while (ind > i2) {
                ans[ind] = 0;
                undo(ind);
                --ind;
            }
        } else {
            assert(!ifright.empty());
            int i2 = ifright.begin()->second;
            while (ind > i2) {
                ans[ind] = 1;
                undo(ind);
                --ind;
            }
        }
        cur ^= 1;
    }
    cout << ans << '\n';

    return 0;
}