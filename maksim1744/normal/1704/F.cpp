/*
    author:  Maksim1744
    created: 31.07.2022 17:45:38
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

// map<pair<string, char>, bool> mem;
// bool calc(string s, char c = 'R') {
//     while (s.size() >= 2 && s[0] == 'W' && s[1] == 'W') s.erase(s.begin());
//     while (s.size() >= 2 && s.back() == 'W' && s[s.size() - 2] == 'W') s.pop_back();
//     pair<string, char> p = {s, c};
//     if (mem.count(p)) return mem[p];

//     for (int i = 0; i + 1 < s.size(); ++i) {
//         if (s[i] == c || s[i + 1] == c) {
//             string t = s;
//             t[i] = t[i + 1] = 'W';
//             if (!calc(t, c ^ 'R' ^ 'B')) return mem[p] = true;
//         }
//     }

//     return mem[p] = false;
// }

map<int, int> mem2;
int calc2(int n) {
    if (n <= 1) return 0;
    if (mem2.count(n)) return mem2[n];
    n -= 2;
    set<int> s;
    for (int a = 0; a <= n; ++a)
        s.insert(calc2(a) ^ calc2(n - a));
    int x = 0;
    while (s.count(x)) ++x;
    return mem2[n + 2] = x;
}

vector<int> v2;
int calc2fast(int n) {
    if (v2.empty()) {
        for (int i = 0; i <= 200; ++i)
            v2.pb(calc2(i));
    }
    if (n < v2.size()) return v2[n];
    return v2[(n - 100) % 34 + 100];
}

void test_case(int test) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cr = count(s.begin(), s.end(), 'R');
    int cb = count(s.begin(), s.end(), 'B');
    if (cr != cb) {
        cout << (cb > cr ? "Bob" : "Alice") << '\n';
        return;
    }

    vector<int> b;
    string x;
    for (int i = 0; i + 1 < n; ++i)
        b.pb(s[i] != s[i + 1]);
    b.pb(0);
    vector<int> v;
    int cur = 0;
    for (int k : b) {
        if (k == 1)
            ++cur;
        else {
            if (cur) v.pb(cur);
            cur = 0;
        }
    }
    ++v;
    int res = 0;
    for (int k : v)
        res ^= calc2fast(k);
    cout << (res == 0 ? "Bob" : "Alice") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // int n = 11;
    // int tot = 0;
    // for (int i = 0; i < (1 << n); ++i) {
    //     string s;
    //     string t;
    //     for (int j = 0; j < n; ++j) {
    //         s.pb("RB"[(i >> j) & 1]);
    //         t.pb(".1"[(i >> j) & 1]);
    //     }
    //     int who = (calc(s) == 0);
    //     if (count(s.begin(), s.end(), 'B') > count(s.begin(), s.end(), 'R')) assert(who == 1);
    //     else if (count(s.begin(), s.end(), 'R') > count(s.begin(), s.end(), 'B')) assert(who == 0);
    //     else {
    //         vector<int> b;
    //         string x;
    //         for (int i = 0; i + 1 < n; ++i)
    //             b.pb(s[i] != s[i + 1]);
    //         b.pb(0);
    //         vector<int> v;
    //         int cur = 0;
    //         for (int k : b) {
    //             if (k == 1)
    //                 ++cur;
    //             else {
    //                 if (cur) v.pb(cur);
    //                 cur = 0;
    //             }
    //         }
    //         ++v;
    //         int res = 0;
    //         show(v);
    //         for (int k : v)
    //             res ^= calc2(k);
    //         if ((res == 0) != who) {
    //             cout << t << ' ' << calc(s, 'R') << ' ' << res << '\n';
    //             ++tot;
    //         }
    //     }
    // }
    // cout << tot << endl;
    // for (int i = 0; i <= 20; ++i)
    //     cout << calc2(i) << ' ';
    // cout << endl;

    // for (int i = 0; i < 1000; ++i)
    //     assert(calc2(i) == calc2fast(i));

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}