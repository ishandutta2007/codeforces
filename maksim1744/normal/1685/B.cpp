/*
    author:  Maksim1744
    created: 25.05.2022 20:44:34
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
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), 'A') != a + ab + ba) {
        cout << "NO\n";
        return;
    }
    if (count(s.begin(), s.end(), 'B') != b + ab + ba) {
        cout << "NO\n";
        return;
    }
    int ind = 0;
    vector<int> odd, evena, evenb;
    while (ind < s.size()) {
        int i2 = ind;
        while (i2 + 1 < s.size() && s[i2 + 1] != s[i2])
            ++i2;
        int len = i2 - ind + 1;
        if (len > 2) {
            if (len % 2 == 0) {
                if (s[ind] == 'A') evena.pb(len);
                else evenb.pb(len);
            } else {
                odd.pb(len);
            }
        } else if (len == 2) {
            if (s[ind] == 'A') --ab;
            else --ba;
        }
        ind = i2 + 1;
    }

    ab = max(ab, 0);
    ba = max(ba, 0);
    auto no = [&]() {
        // assert(false);
    };

    show(ab, ba);
    show(odd, evena, evenb);

    sort(evena.begin(), evena.end());
    reverse(evena.begin(), evena.end());
    sort(evenb.begin(), evenb.end());
    // reverse(evenb.begin(), evenb.end());

    for (int i = 0; i < ab; ++i) {
        if (!evena.empty()) {
            evena.back() -= 2;
            if (evena.back() < 2) evena.pop_back();
            else if (evena.back() == 2) {
                --ab;
                evena.pop_back();
            }
        } else if (!odd.empty()) {
            odd.back() -= 2;
            if (odd.back() < 2) odd.pop_back();
        } else if (!evenb.empty()) {
            assert(evenb.back() > 2);
            int k = evenb.back();
            evenb.pop_back();
            k -= 3;
            if (k >= 2) odd.pb(k);
        } else {
            cout << "NO\n";
            no();
            return;
        }
    }
    sort(evena.begin(), evena.end());
    // reverse(evena.begin(), evena.end());
    sort(evenb.begin(), evenb.end());
    reverse(evenb.begin(), evenb.end());
    for (int i = 0; i < ba; ++i) {
        if (!evenb.empty()) {
            evenb.back() -= 2;
            if (evenb.back() < 2) evenb.pop_back();
            else if (evenb.back() == 2) {
                --ba;
                evenb.pop_back();
            }
        } else if (!odd.empty()) {
            odd.back() -= 2;
            if (odd.back() < 2) odd.pop_back();
        } else if (!evena.empty()) {
            assert(evena.back() > 2);
            int k = evena.back();
            evena.pop_back();
            k -= 3;
            if (k >= 2) odd.pb(k);
        } else {
            cout << "NO\n";
            no();
            return;
        }
    }

    cout << "YES\n";
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