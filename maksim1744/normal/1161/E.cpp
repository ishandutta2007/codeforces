/*
    author:  Maksim1744
    created: 06.05.2019 01:26:30
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        if (n == -1)
            exit(0);
        auto ask = [](vector<pair<int, int>> v) -> string {
            if (v.size() == 0)
                return "";
            cout << "Q " << v.size();
            for (auto [x, y] : v) {
                cout << ' ' << x + 1 << ' ' << y + 1;
            }
            cout << endl;
            string s;
            cin >> s;
            if (s == "-1")
                exit(0);
            return s;
        };
        vector<pair<int, int>> v;
        for (int i = 0; i + 1 < n; i += 2)
            v.pb({i, (i + 1) % n});
        string s1 = ask(v);
        v.clear();
        for (int i = 1; i < n; i += 2)
            v.pb({i, (i + 1) % n});
        string s2 = ask(v);
        // assert(s2.size() + s1.size() == n);
        assert(s1.size() >= s2.size());
        assert(s1.size() <= s2.size() + 1);
        string s;
        for (int i = 0; i < s2.size(); ++i) {
            s.pb(s1[i]);
            s.pb(s2[i]);
        }
        if (s1.size() > s2.size())
            s.pb(s1.back());
        show(s);
        // assert(s.size() == n);
        vector<vector<int>> comp;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i - 1] == '0')
                comp.eb();
            comp.back().pb(i);
        }
        if (comp.size() >= 2 && ask(vector<pair<int, int>>{pair<int, int>{n - 1, 0}}) == "1") {
            for (auto k : comp.back()) {
                comp[0].pb(k);
            }
            comp.pop_back();
        }
        show(comp);
        if (comp.size() <= 3) {
            while (comp.size() < 3)
                comp.eb();
            for (int i = 0; i < 3; ++i) {
                for (auto& t : comp[i]) {
                    ++t;
                }
            }
            cout << "A " << comp[0].size() << ' ' << comp[1].size() << ' ' << comp[2].size() << endl;
            cout << comp[0] << endl << comp[1] << endl << comp[2] << endl;
            continue;
        }
        s = string(comp.size(), '0');
        for (int d = 0; d < 4; ++d) {
            v.clear();
            for (int i = 0; i + d + 2 < comp.size(); i += 4) {
                v.eb(comp[(i + d) % comp.size()][0], comp[(i + d + 2) % comp.size()][0]);
            }
            show(d, v);
            s1 = ask(v);
            for (int i = 0; i < s1.size(); ++i) {
                s[(i * 4 + d) % s.size()] = s1[i];
            }
        }
        show(s);
        vector<int> col(comp.size(), -1);
        col[0] = 0;
        col[1] = 1;
        for (int i = 2; i < comp.size(); ++i) {
            if (s[i - 2] == '1')
                col[i] = col[i - 2];
            else
                col[i] = 3 - col[i - 1] - col[i - 2];
        }
        show(col);
        vector<vector<int>> ans(3);
        for (int i = 0; i < comp.size(); ++i) {
            for (auto y : comp[i]) {
                ans[col[i]].pb(y + 1);
            }
        }
        cout << "A " << ans[0].size() << ' ' << ans[1].size() << ' ' << ans[2].size() << endl;
        cout << ans[0] << endl << ans[1] << endl << ans[2] << endl;
    }
    return 0;
}