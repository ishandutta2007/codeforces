/*
    author:  Maksim1744
    created: 16.04.2021 17:37:48
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
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

void test_case(int test) {
    int n;
    cin >> n;
    vector<string> v(3);
    cin >> v;

    auto gets = [&](string a, string b) {
        assert(count(a.begin(), a.end(), '0') >= a.size() / 2);
        assert(count(b.begin(), b.end(), '0') >= b.size() / 2);

        vector<string> vs(n * 2 + 1);
        for (int i = 0; i < a.size(); ++i) {
            vs[i + 1].pb(a[i]);
        }

        vector<int> have;
        for (int i = 0; i < vs.size(); ++i) {
            if (vs[i] == "0")
                have.pb(i);
        }
        vector<int> need;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == '0') {
                need.pb(i);
            }
        }
        have.resize(min(have.size(), need.size()));
        need.resize(min(have.size(), need.size()));
        assert(need.size() >= n);
        show(a, b);
        show(vs);
        for (int i = 0; i < need.size(); ++i) {
            vs[have[i]] += b.substr(need[i] + 1, (i + 1 == need.size() ? (int)b.size() : need[i + 1]) - need[i] - 1);
        }
        if (!need.empty() && need[0] != 0) {
            vs[0] += b.substr(0, need[0]);
        }
        show(vs);

        string res;
        for (string s : vs)
            res += s;
        return res;
    };

    for (int i = 0; i < 3; ++i) {
        if (count(v[i].begin(), v[i].end(), '0') < n) continue;
        for (int j = 0; j < i; ++j) {
            if (count(v[j].begin(), v[j].end(), '0') < n) continue;
            cout << gets(v[i], v[j]) << '\n';
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (count(v[i].begin(), v[i].end(), '1') < n) continue;
        for (int j = 0; j < i; ++j) {
            if (count(v[j].begin(), v[j].end(), '1') < n) continue;
            for (int k = 0; k < n * 2; ++k) {
                v[i][k] ^= '0' ^ '1';
                v[j][k] ^= '0' ^ '1';
            }
            string s = gets(v[i], v[j]);
            for (int i = 0; i < s.size(); ++i) {
                s[i] ^= '0' ^ '1';
            }
            cout << s << '\n';
            return;
        }
    }
    assert(false);
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